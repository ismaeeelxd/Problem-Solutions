class Solution {
public:
    bool isPalindrome(string s) {
        if(s == " " || s == ""){
            return true;
        }
        string p = "";
        for(int i = 0;i<s.size();++i){
            if(isalnum(s[i]))
                p.push_back(tolower(s[i]));

        }
        s = p;
        reverse(p.begin(),p.end());
        if(s == p)
            return true;
        return false;
    }
};
