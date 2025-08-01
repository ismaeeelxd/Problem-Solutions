class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        for(int i = 2; i <= numRows; ++i){
            vector<int> p(i,0);
            p[0] = 1;
            p[i-1] = 1;
            for(int j = 1; j < i - 1; ++j){
                p[j] = res[i-2][j-1] + res[i-2][j];
            }
            res.push_back(p);
        }
        return res;
    }
};
