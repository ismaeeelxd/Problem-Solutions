class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int t[1000000]={0};
        int x;
        for(const auto &i:nums){
            t[i]++;
            if(t[i] > 1){
                x=i;
                break;
            }
        }
        
        return x;
    }
};
