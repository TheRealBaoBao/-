//2D Version 
//Time Complexity: O(m)
//Space Complexity: O(m*n)
class NumMatrix {
private:
    vector<vector<int>> prefixSum;

public:
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size(), cols = matrix[0].size();
        prefixSum = vector<vector<int>>(rows, vector<int>(cols, 0));

        for (int row = 0; row < rows; row++){
            prefixSum[row][0] = matrix[row][0]
            for(int col = 1; col < cols; col++){
                prefixSum[row][col] = prefixSum[row][col-1] + matrix [row][col];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) { 
        int res = 0;
        for(int row = row1; row <= row2; row++){
            if(col1 > 0){
                res += prefixSum[row][col2] - prefixSum[row][col1-1];
            }
            else{
                res += prefixSum[row][col2];
            }
            return res; 
        }
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */










//1D Version
//Time Complexity: preprocessing O(n), each query O(1)
//Space Complexity: O(n)

class NumArray {
private:
    vector<int> prefix;

public: 
    NumArray(vector<int>& nums) {
        int cur = 0;
        for(int num : nums){
            cur += num;
            prefix.push_back(cur);
        }
    }

    int sumRange(int left, int right) {
        int rightSum = prefix[right];
        int leftSum = left > 0 ? prefix[left - 1] : 0;
        return rightSum - leftSum;
    }   
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
