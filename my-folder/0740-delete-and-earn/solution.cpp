class Solution {
public:
    
    int getMaxPoints(int index, vector<int> &v, vector<int>&memo){    
        if(index >= v.size()){
            return 0;
        }
        if(memo[index]!=-1) return memo[index];
        int leavePoints = getMaxPoints(index+1,v,memo);
        int takePoints = getMaxPoints(index+2,v,memo) + v[index];
        return memo[index] = max(leavePoints,takePoints);
    }
    int deleteAndEarn(vector<int>& nums) {
        int maxN = -1;
        for(auto &num : nums) maxN = max(num,maxN);
        vector<int> v(maxN+1,0);
        vector<int> memo(maxN+1, -1);
        for(auto &num : nums) v[num]+=num;
        return getMaxPoints(0,v,memo);
    }
};
