class Solution {
public:
    bool check(int num) {
        while(num) {
            if(num % 10 == 0) return false;
            num/=10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        for(int i = 1; i < n; ++i) {
            if(check(n - i) && check(i)) {
                return { n-i , i };
            }
        }
        return {};
    }
};
