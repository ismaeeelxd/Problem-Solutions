class Solution {
public:
    string invert(string a) {
        string ret = "";
        for(int i = 0; i < a.size(); ++i) {
            if(a[i] == '1') ret.push_back('0');
            else ret.push_back('1');
        }
        return ret;
    }
    string process(int n) {
        if(n == 1) return "0";
        string si_1 = process(n-1);
        string inverted = invert(si_1);
        reverse(inverted.begin(), inverted.end());
        return si_1 + '1' + inverted;
    }
    char findKthBit(int n, int k) {
        string a = process(n);
        return a[k-1];
    }
};
