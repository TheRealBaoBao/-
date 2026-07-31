class Solution {
public:
    int rotatedDigits(int n) {
        int goodCount = 0;
        for (int i = 1; i <= n; ++i) {
            if (isValidGoodNumber(i)) {
                goodCount++;
            }
        }
        return goodCount;
    }

private:
    bool isValidGoodNumber(int num) {
        bool hasTransformingDigit = false;
        
        while (num > 0) {
            int digit = num % 10;
            
            // If the number contains any of these digits, it becomes invalid
            if (digit == 3 || digit == 4 || digit == 7) {
                return false;
            }
            
            // These digits transform the entire number into a different value
            if (digit == 2 || digit == 5 || digit == 6 || digit == 9) {
                hasTransformingDigit = true;
            }
            
            num /= 10;
        }
        
        // Must contain at least one transforming digit, and no invalid digits
        return hasTransformingDigit;
    }
};
