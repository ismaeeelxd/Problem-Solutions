class Solution {
public:
    int lcp(string word1, string word2) {
        int ans = 0;
        for (int i = 0; i < min(word1.size(), word2.size()); ++i) {
            if (word1[i] == word2[i])
                ans++;
            else
                return ans;
        }
        return ans;
    }
    vector<int> longestCommonPrefix(vector<string>& words) {
        int n = words.size();
        vector<int> ans(n);
        if(n == 1){
            ans[0] = 0;
            return ans;
        }
        vector<int> suffixes(n, 0);
        vector<int> prefixes(n, 0);
        suffixes[n - 1] = 0;
        suffixes[n - 2] = 0;
        for (int i = n - 3; i >= 0; --i) {
            suffixes[i] = max(suffixes[i + 1], lcp(words[i + 1], words[i + 2]));
        }
        prefixes[0] = 0;
        prefixes[1] = 0;
        for (int i = 2; i < words.size(); ++i) {
            prefixes[i] = max(prefixes[i - 1], lcp(words[i - 1], words[i - 2]));
        }

        ans[0] = suffixes[0];
        ans[n - 1] = prefixes[n - 1];
        for (int i = 1; i < n - 1; ++i) {
            int cross = lcp(words[i - 1], words[i + 1]);
            ans[i] = max(cross, prefixes[i]);
            ans[i] = max(ans[i], suffixes[i]);
        }

        return ans;
    }
};
