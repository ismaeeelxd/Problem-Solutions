class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n <= 0) return false;
        double t = log2(n) / log2(3);
        return abs(t - round(t)) < 1e-10; 
    }
};
