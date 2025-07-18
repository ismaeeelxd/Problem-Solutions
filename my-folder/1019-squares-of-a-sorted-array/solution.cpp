class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        int pos = right;
        vector<int> res(nums.size(),0);
        while(left <= right){
            int leftSq = nums[left] * nums[left];
            int rightSq = nums[right] * nums[right];
            if(leftSq > rightSq){
                res[pos] = leftSq;
                pos--;
                left++;
            } else {
                res[pos] = rightSq;
                pos--;
                right--;
            }
        }
        
        return res;

    }
};
