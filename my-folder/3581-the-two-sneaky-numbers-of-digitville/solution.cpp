class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        int arr[200] = {0};
        vector<int> res;
        for(int i = 0; i < nums.size(); ++i) {
            arr[nums[i]]++;
            if(arr[nums[i]] > 1) res.push_back(nums[i]);
        }
        return res;
    }
};
