class Solution {
public:
    int hammingWeight(int n) {
        int counter = 0;
        for(int i = 0; i < 31; ++i) {
            int bit = n & 1;
            if(bit) counter++;
            n = n >> 1;
        }
        if(n&1) counter++;
        return counter;
    }
};
