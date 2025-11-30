class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        long long need = 0;
        for(auto num: nums) {
            need = (need + num) % p;
        }
        int res = n;
        unordered_map<int,int> prefix = {{0, -1}};
        int cur = 0;
        for(int i = 0; i < n; ++i) {
            cur = (cur + nums[i]) % p;
            prefix[cur] = i;
            int want = (cur - need + p) % p;
            if(prefix.count(want))
                res = min(res, i - prefix[want]);
        }

        return res < n ? res: -1;

    }
};
