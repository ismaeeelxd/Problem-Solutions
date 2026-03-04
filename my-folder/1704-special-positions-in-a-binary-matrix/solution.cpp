class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rows(mat.size(),0);
        vector<int> cols(mat[0].size(),0);
        for(int i= 0;i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) if(mat[i][j]) {
                rows[i]++;
                cols[j]++;
            } 
        }
        int counter = 0;
        for(int i = 0; i < mat.size(); ++i) {
            if(i == 0) {
                cout << rows[0] << endl;
                cout << cols[0] << endl; 
            }
            for(int j = 0; j < mat[0].size(); ++j) if(mat[i][j] == 1 && rows[i] == cols[j] && rows[i] == 1) counter++; 
        }
        return counter;
    }
};
