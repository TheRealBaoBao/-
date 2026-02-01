//Once any element's count exceeds n/2, it must be the majority element.
//O(n), O(n) space and time
class Solution{
public:
  int majorityElement(vector<int>& nums){
    unordered_map<int, int> count;
    int res = 0, maxCount = 0;
    for (int num: nums){
      count[num]++;
      if(count[num] > maxCount) {
        res = num;
        maxCount = count[num];
      }
    }
    return res; 
  }
};

//linear time and O(1) space - Boyer-Moore Voting Algorithm
class Solution{
public:
  int majorityElement(vector<int>& nums) {
        int res = 0, count = 0;

        for (int num : nums) {
            if (count == 0) {
                res = num;
            }
            count += (num == res) ? 1 : -1;
        }
        return res;
    }
};
