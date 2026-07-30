#include <string>
#include <iostream>

class Solution {
public:
    int monotoneIncreasingDigits(int n) {
        std::string s = std::to_string(n);
        int size = s.length();
        int marker = size; // Tracks where '9's should start

        // Traverse from right to left
        for (int i = size - 1; i > 0; --i) {
            if (s[i - 1] > s[i]) {
                marker = i;
                s[i - 1]--; // Decrement the higher digit
            }
        }

        // Fill all digits from the marker to the end with '9'
        for (int i = marker; i < size; ++i) {
            s[i] = '9';
        }

        return std::stoi(s);
    }
};
