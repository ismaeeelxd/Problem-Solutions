class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> sol(2);
        sol[0] = -1;
        sol[1] = -1;
        sort(nums.begin(), nums.end());
        int n = nums.size(); // 10
        int freq[10001] = {0};
        for(int i = 0; i < nums.size(); ++i) {
            int number = nums[i]; // 1
            freq[number - 1]++;
        }

        for(int i = 0; i < n; ++i) {
            if(freq[i] == 2) {
                sol[0] = i + 1;
            }
            if(freq[i] == 0) {
                sol[1] = i + 1;
            }
        }

        return sol;
    }
};

