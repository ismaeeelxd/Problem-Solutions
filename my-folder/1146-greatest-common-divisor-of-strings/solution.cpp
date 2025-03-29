class Solution {
public:
    int gcd(int a, int b) {
        return b == 0 ? a : gcd(b, a % b);
    }


    string gcdOfStrings(string str1, string str2) {
        string merged = str1+str2;
        string merged_2 = str2+str1;
        if(merged!=merged_2)
            return "";
        int gc = gcd(str1.size(),str2.size());
        return str1.substr(0,gc) ;
        
    }
};
