class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        int sArr[27] ={0};
        int tArr[27] = {0};
        for(int i = 0 ;i<s.size();++i){
            sArr[s[i] - 'a']++;
            tArr[t[i] - 'a']++;
        }
        for(int i = 0;i<27;++i){
            if(sArr[i] != tArr[i])
                return false;
        }
        return true;

    }
};
