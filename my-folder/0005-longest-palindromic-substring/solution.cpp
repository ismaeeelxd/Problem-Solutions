class Solution {
public:
    string memo[1001][1001];
    bool visited[1001][1001];
    bool isPal[1001][1001];

    void preprocessIsPal(const string& s) {
        int n = s.size();
        for (int len = 1; len <= n; ++len) {
            for (int start = 0; start + len - 1 < n; ++start) {
                int end = start + len - 1;
                if (s[start] == s[end]) {
                    if (len <= 2)
                        isPal[start][end] = true;
                    else
                        isPal[start][end] = isPal[start + 1][end - 1];
                } else {
                    isPal[start][end] = false;
                }
            }
        }
    }

    string dp(int start, int end, const string& s) {
        if (start > end)
            return "";
        if (visited[start][end])
            return memo[start][end];

        visited[start][end] = true;

        if (isPal[start][end])
            return memo[start][end] = s.substr(start, end - start + 1);

        string left = dp(start + 1, end, s);
        string right = dp(start, end - 1, s);

        return memo[start][end] = (left.size() >= right.size() ? left : right);
    }

    string longestPalindrome(string s) {
        memset(visited, 0, sizeof(visited));
        preprocessIsPal(s);
        return dp(0, s.size() - 1, s);
    }
};

