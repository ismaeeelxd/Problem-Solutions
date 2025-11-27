class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>v1(nums.begin(), nums.begin()+n);
        vector<int>v2(nums.begin()+n,nums.end());
        vector<int> res;
        int k = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(i % 2 == 0) res.push_back(v1[k]);
            else res.push_back(v2[k++]);
        }
        return res;
    }
};
