class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<bool> d(n, 0);
        for(auto&n_ : nums) {
            d[n_] = 1;
        }
        vector<int> res;
        for(int i = 1; i <= n; ++i) {
            if(d[i] == 0) res.push_back(i);
        }
        return res;
    }
};
