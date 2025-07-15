class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int maximum = -1;
        for(int i = 0; i < accounts.size(); ++i){
            int s = 0;
            for(int j = 0; j < accounts[0].size(); ++j){
                s+=(accounts[i][j]);
            }
            maximum = max(maximum,s);
        }
        return maximum;
    }
};
