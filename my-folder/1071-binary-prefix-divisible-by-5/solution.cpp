class Solution {
public:
vector<bool> prefixesDivBy5(vector<int>& nums) {
    int cur = 0;
    vector<bool> res(nums.size());

    for (int i = 0; i < nums.size(); i++) {
        cur = (cur * 2 + nums[i]) % 5;
        res[i] = (cur == 0);
    }

    return res;
}
};
