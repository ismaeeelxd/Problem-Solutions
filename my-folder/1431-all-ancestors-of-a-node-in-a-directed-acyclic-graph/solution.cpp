class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> rev(n);
        for (auto &e : edges)
            rev[e[1]].push_back(e[0]);

        vector<set<int>> temp(n);

        for (int u = 0; u < n; ++u) {
            solve(u, rev, temp);
        }

        vector<vector<int>> ans(n);
        for (int u = 0; u < n; ++u) {
            ans[u].assign(temp[u].begin(), temp[u].end());
        }
        return ans;
    }

    const set<int>& solve(int u,
                          const vector<vector<int>>& rev,
                          vector<set<int>>& memo) 
    {
        if (!memo[u].empty() || rev[u].empty()) {
            return memo[u];
        }

        for (int p : rev[u]) {
            const set<int>& parentSet = solve(p, rev, memo);

            memo[u].insert(parentSet.begin(), parentSet.end());

            memo[u].insert(p);
        }

        return memo[u];
    }
};
