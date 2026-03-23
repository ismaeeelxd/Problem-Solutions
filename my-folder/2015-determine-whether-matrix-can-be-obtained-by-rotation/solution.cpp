class Solution {
public:


    vector<vector<int>> rotate(vector<vector<int>>& mat) {
        // awl col ba2a awl row w bn2ra mn taht le fo2
        vector<vector<int>> res(mat.size(), vector<int>(mat[0].size(), 0));
        int rowI = 0;
        int colJ = 0;
        for(int i = 0; i < mat[0].size() ; ++i) {
            for(int j = mat.size() - 1; j >= 0; --j) {
                res[rowI][colJ++] = mat[j][i];
            }
            colJ = 0;
            rowI++;
        }
        return res;
    }
    void print(vector<vector<int>> mat) {
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) cout << mat[i][j] << " ";
            cout << endl;
        }
    }

    bool areEqual(vector<vector<int>>& mat, vector<vector<int>>& target) {
        for(int i = 0; i < mat.size(); ++i) {
            for(int j = 0; j < mat[0].size(); ++j) if(mat[i][j] != target[i][j]) return false;
        }
        return true;
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        vector<vector<int>> rotatedMatrix = mat;
        for(int i = 0; i < 4; ++i) {
            if(areEqual(rotatedMatrix, target)) return true;
            rotatedMatrix = rotate(rotatedMatrix); 
        }
        return false;
    }
};
