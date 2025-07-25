class Solution {
public:
    int maxSum(vector<int>& nums) {
        set<int> s;
        for(auto num : nums) s.insert(num);
        int maxSum = -1e5;
        int currentSum = -1e5;
        for(auto num : s){
            currentSum = max(num, currentSum+num);
            maxSum = max(maxSum,currentSum);
        }
        return maxSum;
    }
};
