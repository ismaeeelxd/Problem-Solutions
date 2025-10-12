class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        for(int i = 0; i < nums.size(); ++i) {
            int a = nums[i];
            if(i > 0) {
                if(a == nums[i-1]) continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            int last_b = -1;
            int last_c = -1;
            while(left < right) {
                int b = nums[left], c = nums[right];
                int sum = a + b + c;
                if(sum < 0) left++;
                else if(sum > 0) right--;
                else {
                    left++;
                    right--;
                    if(b == last_b && c == last_c) continue;
                    last_c = c;
                    last_b = b;
                    res.push_back({ a, b, c });
                }
            }
        }
        return res;
    }
};
