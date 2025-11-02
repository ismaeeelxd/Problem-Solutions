class Solution {
public:
    const int wall = -1;
    const int guard = -2;
    const int free = 0;
    const int seen = 1;
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> grid(m, vector<int>(n));
        int acc = guards.size() + walls.size();
        int totalCells = n * m;
        for (int i = 0; i < walls.size(); ++i) {
            int x = walls[i][0];
            int y = walls[i][1];
            grid[x][y] = wall;
        }
        for (int i = 0; i < guards.size(); ++i) {
            int x = guards[i][0];
            int y = guards[i][1];
            grid[x][y] = guard;
        }

        for (int i = 0; i < m; ++i) {
            bool seenGuard = false;
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == wall)
                    seenGuard = false;
                else if (grid[i][j] == guard)
                    seenGuard = true;
                else if (seenGuard) {
                    if (grid[i][j] != seen)
                        acc++;
                    grid[i][j] = seen;
                }
            }
        }

        for (int i = 0; i < m; ++i) {
            bool seenGuard = false;
            for (int j = n - 1; j >= 0; --j) {
                if (grid[i][j] == wall)
                    seenGuard = false;
                else if (grid[i][j] == guard)
                    seenGuard = true;
                else if (seenGuard) {
                    if (grid[i][j] != seen)
                        acc++;
                    grid[i][j] = seen;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            bool seenGuard = false;
            for (int i = 0; i < m; ++i) {
                if (grid[i][j] == wall)
                    seenGuard = false;
                else if (grid[i][j] == guard)
                    seenGuard = true;
                else if (seenGuard) {
                    if (grid[i][j] != seen)
                        acc++;
                    grid[i][j] = seen;
                }
            }
        }

        for (int j = 0; j < n; ++j) {
            bool seenGuard = false;
            for (int i = m - 1; i >= 0; --i) {
                if (grid[i][j] == wall)
                    seenGuard = false;
                else if (grid[i][j] == guard)
                    seenGuard = true;
                else if (seenGuard) {
                    if (grid[i][j] != seen)
                        acc++;
                    grid[i][j] = seen;
                }
            }
        }

        return totalCells - acc;
    }
};
