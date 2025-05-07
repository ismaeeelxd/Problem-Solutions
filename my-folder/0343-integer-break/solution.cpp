class Solution {
public:
    int integerBreak(int n) {
        int memo[59];
        memset(memo,-1,sizeof(memo));
        return solve(n,memo);
    }

    int solve(int n, int (&memo) [59]){
        if(n == 2)
            return 1;
        else if(n <= 1) return 0;
        int maximum = -1;
        auto &ret = memo[n];
        if(memo[n] != -1)
            return ret;
        for(int i = 1; i < n ;++i){
            int rec = solve(n-i,memo);
            maximum = max(max(i * (n-i), i * rec),maximum);
        }
        return ret = maximum;
    }
};
