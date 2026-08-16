#include <iostream>
#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> result;
        std::string current = "";
        backtrack(result, current, 0, 0, n);
        return result;
    }

private:
    void backtrack(std::vector<std::string>& result, std::string& current, int open, int close, int max_pairs) {
        // Base case: If the current string reaches the maximum required length
        if (current.length() == max_pairs * 2) {
            result.push_back(current);
            return;
        }

        // Rule 1: You can always add an opening parenthesis if we haven't reached the limit
        if (open < max_pairs) {
            current.push_back('(');
            backtrack(result, current, open + 1, close, max_pairs);
            current.pop_back(); // Backtrack
        }

        // Rule 2: You can only add a closing parenthesis if it matches an open one
        if (close < open) {
            current.push_back(')');
            backtrack(result, current, open, close + 1, max_pairs);
            current.pop_back(); // Backtrack
        }
    }
};
