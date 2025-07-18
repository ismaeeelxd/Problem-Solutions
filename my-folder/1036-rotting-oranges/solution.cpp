class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, vector<int>> adjList;
        queue<int> q;
        vector<int> dist(1500, 1e8);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 0)
                    continue;
                if (grid[i][j] == 2) {
                    q.push(i * n + j);
                    dist[i * n + j] = 0;
                }
                if (i - 1 >= 0 && grid[i - 1][j] > 0)
                    adjList[i * n + j].push_back((i - 1) * n + j);
                if (i + 1 < m && grid[i + 1][j] > 0)
                    adjList[i * n + j].push_back((i + 1) * n + j);
                if (j + 1 < n && grid[i][j + 1] > 0)
                    adjList[i * n + j].push_back(i * n + (j + 1));
                if (j - 1 >= 0 && grid[i][j - 1] > 0)
                    adjList[i * n + j].push_back(i * n + (j - 1));
            }
        }
        bool vis[150] = {0};
        int maxTime = 0;
        while (!q.empty()) {
            int idx = q.front();
            q.pop();
            if (vis[idx])
                continue;
            vis[idx] = 1;
            for (int i = 0; i < adjList[idx].size(); ++i) {
                
                if (dist[adjList[idx][i]] > dist[idx] + 1){
                    dist[adjList[idx][i]] = dist[idx] + 1;
                    maxTime = max(dist[idx] + 1, maxTime);
                    q.push(adjList[idx][i]);
                }
                    
                
            }
        }

        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n; ++j){
                if(grid[i][j] == 1)
                if(dist[i*n+j] == 1e8){
                    return -1;
                }
            }
        }

        return maxTime;
    }
};
