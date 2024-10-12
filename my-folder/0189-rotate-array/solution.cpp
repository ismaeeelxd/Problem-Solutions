class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        k = k%nums.size();
        vector<int> arr;
        for(int i = k;i>=1;--i){
            arr.push_back(nums[nums.size()-i]);
        }
        for(int i = 0;i<nums.size()-k;++i){
            arr.push_back(nums[i]);
        }
        nums = arr;
    }
};
