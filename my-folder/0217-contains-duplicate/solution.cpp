class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int,int>t;
        for(auto f:nums){
            t[f]++;
            if(t[f] > 1)
                return true;
            
        }
        return false;
    }
};
