class Solution {
public:
    int dp[302][30][30];
    pair<int, int> grid[101];
    string word;
    int solve(int i, char lastSelected_1, char lastSelected_2) {
        if (i >= word.size()) {
            return 0;
        }

        auto& ret = dp[i + 1][lastSelected_1 - 'A'][lastSelected_2 - 'A'];
        if (ret != -1) {
            return ret;
        }
        if (lastSelected_1 == '^') {
            return ret = solve(i + 1, word[i], lastSelected_2);
        }

        int secondFingerDistance = 1e9;
        char lastSelectedChar_1 = lastSelected_1;
        char currentChar = word[i];

        auto [x_1, y_1] = grid[lastSelectedChar_1];
        auto [x_0, y_0] = grid[currentChar];

        int firstFingerDistance =
            solve(i + 1, currentChar , lastSelected_2) + (abs(x_1 - x_0) + abs(y_1 - y_0));

        if (lastSelected_2 == '^') {
            secondFingerDistance = solve(i + 1, lastSelected_1, currentChar);
        } else {
            char lastSelectedChar_2 = lastSelected_2;
            auto [x_2, y_2] = grid[lastSelectedChar_2];
            secondFingerDistance =
                solve(i + 1, lastSelected_1, currentChar) + (abs(x_2 - x_0) + abs(y_2 - y_0));
        }

        return ret = min(firstFingerDistance, secondFingerDistance);
    }
    int minimumDistance(string w) {
        memset(dp, -1, sizeof(dp));
        word = w;
        char current = 'A';
        for (int i = 0; i < 5; ++i) {
            for (int j = 0; j < 6; ++j) {
                grid[current] = {i, j};
                current++;
            }
        }
        return solve(0, '^', '^');
    }
};
