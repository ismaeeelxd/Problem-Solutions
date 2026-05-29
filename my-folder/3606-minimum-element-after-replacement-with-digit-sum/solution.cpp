class Solution {
public:
    int minElement(vector<int>& nums) {
        int total = 1e9;
        for(int &num : nums) {
            int sum = 0;
            while(num != 0) {
                sum+=num%10;
                num/=10;
            }
            total = min(sum,total);
        }

        return total;
    }
};
