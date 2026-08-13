class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> result;
      
        // Generate all Gray code values for n bits
        // Total number of Gray codes for n bits is 2^n
        int totalCodes = 1 << n;  // Equivalent to 2^n
      
        for (int i = 0; i < totalCodes; ++i) {
            // Convert binary number i to its corresponding Gray code
            // Formula: Gray(i) = i XOR (i right-shifted by 1)
            // This ensures adjacent codes differ by exactly one bit
            int grayValue = i ^ (i >> 1);
            result.push_back(grayValue);
        }
      
        return result;
    }
};
