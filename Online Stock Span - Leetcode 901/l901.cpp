class StockSpanner {
public:
    // Constructor initializes an empty stock spanner
    StockSpanner() {
    }
  
    // Calculates and returns the span of the current price
    // Span is defined as the maximum number of consecutive days (including today)
    // where the stock price was less than or equal to today's price
    int next(int price) {
        // Initialize span count to 1 (current day)
        int span = 1;
      
        // Pop all elements from stack that have price less than or equal to current price
        // and accumulate their spans
        while (!priceStack.empty() && priceStack.top().first <= price) {
            span += priceStack.top().second;
            priceStack.pop();
        }
      
        // Push current price and its calculated span onto the stack
        priceStack.emplace(price, span);
      
        return span;
    }
  
private:
    // Stack stores pairs of (price, span)
    // Maintains a monotonic decreasing stack of prices
    std::stack<std::pair<int, int>> priceStack;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */
