class Solution {
public:
    int smallestNumber(int n) {
        int x = 0;
        int i = 0;
        for (; x < n; ++i) {
            x+=(pow(2,i));
        }
        return x;
    }
};
