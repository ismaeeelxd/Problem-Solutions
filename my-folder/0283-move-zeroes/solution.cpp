class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int counter=0;
        vector<int> t;
        for(int i = 0;i<nums.size();++i)
            if(nums[i] == 0)
                counter++;
            else t.push_back(nums[i]);
        while(counter--)
            t.push_back(0);
        nums = t;
    }
};
