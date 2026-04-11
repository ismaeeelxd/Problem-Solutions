class Solution {
public:

    int minimumDistance(vector<int>& nums) {
        vector<int> arr[100005];
        int min_ = INT_MAX;

        for(int y = 0; y < nums.size(); ++y) {
            arr[nums[y]].push_back(y);
            vector<int> &val = arr[nums[y]];
            if(val.size() >=3) {
                int k = val.size() - 1;
                int j = k-1;
                int i = k-2;
                min_ = min(min_, abs(val[i] - val[j]) + abs(val[j] - val[k]) + abs(val[k] -val[i]));

            }

        }

        return min_ != INT_MAX ? min_ : -1;
    }
};
