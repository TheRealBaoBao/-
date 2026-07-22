#include <vector>

class Solution {
public:
    bool isRectangleOverlap(std::vector<int>& rec1, std::vector<int>& rec2) {
        // Check if one rectangle is to the left, right, top, or bottom of the other
        if (rec1[2] <= rec2[0] || // rec1 is to the left of rec2
            rec2[2] <= rec1[0] || // rec2 is to the left of rec1
            rec1[3] <= rec2[1] || // rec1 is below rec2
            rec2[3] <= rec1[1])   // rec2 is below rec1
        {
            return false;
        }
        return true;
    }
};
