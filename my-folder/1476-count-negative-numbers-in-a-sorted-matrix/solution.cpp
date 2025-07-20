class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;
        for(int i = 0; i < m; ++i){
            if(grid[i][n - 1] < 0){
                int left = 0;
                int right = n - 1;
                while(left <= right){
                    int mid = left + (right - left) / 2;
                    if(grid[i][mid] >= 0) left = mid + 1;
                    else right = mid - 1;
                }
                count+=(n - left);
            }
        }
        return count;
    }
};
