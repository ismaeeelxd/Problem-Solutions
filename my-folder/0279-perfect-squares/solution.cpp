class Solution {
public:


    bool isPerfectSquare(long long x)
    {
        // Find floating point value of
        // square root of x.
        if (x >= 0) {

            long long sr = sqrt(x);
            
            // if product of square root 
            //is equal, then
            // return T/F
            return (sr * sr == x);
        }
        // else return false if n<0
        return false;
    }
    int memo[10001];
    int numSquares(int n){
        memset(memo,-1,sizeof(memo));
        return solve(n);
    }
    int solve(int n) {
        if(n == 0)
            return 0;
        int minim = 1e9;
        auto &ret = memo[n];
        if(ret!=-1) return ret;
        for(int i = 1; i * i <= n; i++){
            int rem = n - (i * i);
                int &least_num_sqs = memo[rem];
                if(least_num_sqs == -1){
                    least_num_sqs = numSquares(rem);
                }
                minim = min(minim,least_num_sqs+1);
        }        
        return ret = minim;
    }
};
