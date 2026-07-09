#include <vector>
#include <queue>
#include <algorithm>

class Solution {
public:
    int findMaximizedCapital(int k, int w, std::vector<int>& profits, std::vector<int>& capital) {
        int n = profits.size();
        std::vector<std::pair<int, int>> projects(n);
        
        // Combine capital and profit into pairs
        for (int i = 0; i < n; ++i) {
            projects[i] = {capital[i], profits[i]};
        }
        
        // Sort projects by their capital requirement
        std::sort(projects.begin(), projects.end());
        
        std::priority_queue<int> maxProfitHeap;
        int i = 0;
        
        while (k > 0) {
            // Push all projects we can afford with our current capital 'w' into the heap
            while (i < n && projects[i].first <= w) {
                maxProfitHeap.push(projects[i].second);
                i++;
            }
            
            // If we can't afford any more projects, break
            if (maxProfitHeap.empty()) {
                break;
            }
            
            // Pick the project with the maximum profit
            w += maxProfitHeap.top();
            maxProfitHeap.pop();
            k--;
        }
        
        return w;
    }
};
