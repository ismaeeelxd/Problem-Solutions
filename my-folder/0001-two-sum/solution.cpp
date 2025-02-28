class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> s;
        vector<int> ans;
        for(int i = 0;i<nums.size();++i){
            if(s.contains(target - nums[i]) && (s[target-nums[i]] != i)){
                ans.push_back(i);
                ans.push_back(s[target-nums[i]]);
                break;
            } 
            s[nums[i]] = i;

        }
        return ans;
    }
};
