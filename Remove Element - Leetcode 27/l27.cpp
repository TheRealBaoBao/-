//We use a write pointer k that tracks where the next valid element should go.
//As we scan through the array, whenever we find an element that is not equal to val, we write it at position k and move k forward.
//At the end, everything before index k contains valid elements.

//time complexity: o(n), space complexity: o(1)

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] != val){
                nums[k++] = nums[i];
            }
        }
        return k;
    }
};
