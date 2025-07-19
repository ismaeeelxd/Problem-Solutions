class Solution {
public:
    double myPow(double x, int n) {
        if(n == 1) return x;
        if(n == -1) return 1/x;
        if(n == 0) return 1;
        double p = myPow(x, n/2);
        if(n > 0) return n & 1 ? p * p * x : p * p;
        return n & 1 ? p * p * 1/x : p * p;
    }
};
