class Solution {
public:
    int reverse(int x) {
        long long reversed = 0;
        bool isNegative = false;
        long long n = x;
        if (x < 0) {
            isNegative = true;
            n = llabs((long long)x);
        }

        while (n != 0) {
            int lastDigit = n % 10;
            n /= 10;
            reversed = reversed * 10 + lastDigit;
        }

        if (isNegative)
            reversed = -(long long)reversed;

        return (reversed > INT_MAX || reversed < INT_MIN) ? 0 : (int)reversed;
    }
};
