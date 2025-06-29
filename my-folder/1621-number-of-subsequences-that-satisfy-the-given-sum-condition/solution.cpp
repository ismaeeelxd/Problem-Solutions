class Solution {
public:
    int modPow(int base, int exp, int mod) {
        long long result = 1;
        long long b = base % mod;

        while (exp > 0) {
            if (exp & 1) {
                result = (result * b) % mod;
            }
            b = (b * b) % mod;
            exp >>= 1;
        }

        return result;
    }
    const int MOD = 1e9 + 7;
    int numSubseq(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int ans = 0;
        for (int i = 0; i < n; ++i) {
            int l = i;
            int r = n - 1;
            int t = target - nums[i];
            int idx = -1;
            while (l <= r) {
                int mid = l + (r - l) / 2;
                if (nums[mid] > t) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                    idx = mid;
                }
            }

            if (idx != -1) {
                ans = (ans + modPow(2, idx - i, MOD)) % MOD;
            }
        }

        return (ans);
    }
};
