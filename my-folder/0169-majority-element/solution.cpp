class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int>counter;
        int times = nums.size()/2;
        for(int i = 0;i<nums.size();++i){
            counter[nums[i]]++;
            if(counter[nums[i]] > times)
                return nums[i];
        }
        return -1;
    }
};
