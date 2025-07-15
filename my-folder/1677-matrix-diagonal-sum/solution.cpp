class Solution {
public:
    int diagonalSum(vector<vector<int>>& mat) {
        if(mat[0].size() == 1) return mat[0][0];
        int n = mat.size() / 2;
        int sum = 0;
        for(int i = 0, j = 0; i < mat.size() && j < mat.size(); ++i, ++j) sum+=mat[i][j];
        for(int i = 0, j = mat.size()-1; i < mat.size() && j < mat.size(); ++i, --j) if(i == n && j == n && mat.size() & 1) continue; else sum+= mat[i][j];
        return sum;
    }
};
