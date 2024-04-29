class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int>t;
        for(int i = 0;i<nums.size();++i)
                t[nums[i]]++;
        
        for(auto it = t.begin();it!=t.end();++it)
            if(it->second == 1)
                return it->first;
            
        return 0;
    }
};
