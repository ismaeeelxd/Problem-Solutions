class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> sum(n, vector<int>(n, 0));        
        for(int i = 0; i < grid.size(); ++i) {

                if(grid[i][grid.size()-1] == 1) sum[i][grid.size()-1] = 1;
                else sum[i][grid.size()-1] =0; 

            for(int j = grid[0].size() - 2; j >= 0 ; --j) {
                if(grid[i][j] == 1) sum[i][j] = 1;
                else {
                    if(sum[i][j+1] == 1) sum[i][j] = 1;
                }
            }
        }
        int swaps = 0;
        for(int i = 0; i < grid.size() - 1; ++i) {
            int swapIdx = i;
            if(sum[i][i+1] == 0) continue;

            for(int j = i+1; j < grid.size(); ++j) {

                if(sum[j][i + 1] == 0) {
                    swapIdx = j;
                    break;
                }
            }
            if(swapIdx != i) {
                swaps+= (swapIdx - i);
                for(int k = swapIdx; k > i; k--) {
                    swap(grid[k],grid[k-1] );
                    swap(sum[k], sum[k - 1]);
                } 
            } else {
                if(sum[i][i+1] != 0) return -1;
            }
        }
        return swaps;
    }
};
