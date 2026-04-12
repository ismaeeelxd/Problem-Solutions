class Solution {
public:
    bool doesBreak(string s1 , string s2) {
        int freq[27] = {0};
        const char a = 'a';
        for(int i = 0; i < s1.size(); ++i) {
            freq[s1[i] - a]++;
        }

        for(int i = 0; i < s2.size(); ++i) {
            int j = s2[i] - a;
            while(j < 27 && freq[j] == 0) j++;
            if(j == 27) return false;
            freq[j]--;
        }
        return true;
    }

    bool checkIfCanBreak(string s1, string s2) {
        return doesBreak(s1,s2) || doesBreak(s2,s1);
    }
};
