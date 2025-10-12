class Solution {
public:
    int totalPaths = 0;
    vector<vector<int>> grid_;
    vector<pair<int, int>> pos = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
    int isValid(int r, int c) {
        if (r < 0 || r >= grid_.size() || c >= grid_[0].size() || c < 0)
            return false;
        if (grid_[r][c] == -2)
            return false;
        if (grid_[r][c] == -1)
            return false;

        return true;
    }

    void solve(int r, int c, int count) {
        if (grid_[r][c] == 2) {
            if(!count) totalPaths++;
            return;
        }
        int i = r;
        int j = c;
        grid_[i][j] = -2;

        for (auto p : pos) {
            if (isValid(i + p.first, j + p.second)) {
                solve(i + p.first, j + p.second, count - 1);
            }
        }
        grid_[i][j] = 0;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        grid_ = grid;
        int r = -1;
        int c  = -1;
        int count = 0;
        for(int i = 0; i < grid.size(); ++i) {
            for(int j = 0; j < grid[0].size(); ++j){
                if(grid[i][j] == 0) count++;
                if(grid[i][j] == 1){
                    r = i;
                    c = j;        
                }

            } 
        }
        solve(r,c,count + 1);
    
        return totalPaths;
    }
};
