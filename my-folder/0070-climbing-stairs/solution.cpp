class Solution {
public:

    int getDistinctWays(int n, vector<int>& mem) {
        if(n == 0) {
            return 1;
        } else if(n < 0) return 0;
        auto &ret = mem[n];
        if(ret != -1) return mem[n];
        int opt1 = getDistinctWays(n-1, mem);
        int opt2 = getDistinctWays(n-2, mem);
        return mem[n] =  opt1+opt2;

    }
    int climbStairs(int n) {
        vector<int> mem(n + 2,-1);
        return getDistinctWays(n, mem);
    }
};
