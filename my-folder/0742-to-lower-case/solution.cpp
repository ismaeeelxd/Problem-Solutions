class Solution {
public:
    string toLowerCase(string s) {
        char lower_cased [] = {
            'a',
            'b',
            'c',
            'd',
            'e',
            'f',
            'g',
            'h',
            'i',
            'j',
            'k',
            'l',
            'm',
            'n',
            'o',
            'p',
            'q',
            'r',
            's',
            't',
            'u',
            'v',
            'w',
            'x',
            'y',
            'z'
        };

        for(char &a : s){
            if(a >= 65 && a <= 90) a = lower_cased[a - 65];
        }
        return s;
    }
};
