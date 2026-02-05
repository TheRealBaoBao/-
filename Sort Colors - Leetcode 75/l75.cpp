
//Counting Sort -- Since there are only three possible values (0, 1, 2), we can count how many times each appears in a single pass. Then we overwrite the array in a second pass, placing the correct number of 0s, followed by 1s, followed by 2s. This is a classic application of counting sort.
//Time Complexity: O(n), space O(1)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        vector<int> count(3);
        for (int& num : nums) {
            count[num]++;
        }

        int index = 0;
        for (int i = 0; i < 3; i++) {
            while (count[i]-- > 0) {
                nums[index++] = i;
            }
        }
    }

};

//Brute force O(nlogn)
class Solution {
public:
    void sortColors(vector<int>& nums) {
        sort(nums.begin(), nums.end());
    }
};
