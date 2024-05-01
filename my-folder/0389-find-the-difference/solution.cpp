class Solution {
public:
    char findTheDifference(string s, string t) {
        int Ssum=0;
        int tSum=0;
        for(int i = 0;i<s.size();++i){
            Ssum+=s[i];
            tSum+=t[i];
        }
        tSum+=t[t.size()-1];
        return (char)(tSum-Ssum);
    }
};
