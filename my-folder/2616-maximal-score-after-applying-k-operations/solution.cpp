class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long score = 0;
        priority_queue<long long> t(nums.begin(),nums.end());

        while(k--){
            long long x = t.top();
            t.pop();
            t.push(ceil(double(x)/3.0));
            score+=x;
        }
        return score;
    }
};
