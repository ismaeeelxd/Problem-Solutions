class Solution {
public:

    int getBit(int n) {
        return n & 1;
    }
    int reverseBits(int n) {
        int reverse = 0;
        for(int i = 0; i < 31; ++i) {
            int bit = getBit(n);
            n = n >> 1;
            reverse|=bit;
            reverse = reverse << 1;
        }
        reverse |= n;
        return reverse;
    }
};
