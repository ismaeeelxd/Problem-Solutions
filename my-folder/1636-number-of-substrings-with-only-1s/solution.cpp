class Solution {
public:
    int numSub(string s) {
        const char one = '1';
        const int MOD = 1e9 + 7;
        int j = -1;
        int ret = 0;
        for (int i = 0; i < s.size(); ++i) {
            // 0110111
            if (s[i] == one) {
                j = i;
                while (j < s.size() && s[j] == one)
                    j++;
                int characters = (j - i);
                int chars_ = (j - i + 1);
                long long product = (1LL * characters * chars_) % MOD;
                ret += (product / 2);
                i = j;
            }
        }
        return ret;
    }
};
