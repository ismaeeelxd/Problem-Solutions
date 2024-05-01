class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string word = "";
        int i = 0;
        while(i!=word1.size() && i!=word2.size()){
            word.push_back(word1[i]);
            word.push_back(word2[i]);
            ++i;
        }
        if(!word1.empty()){
            word = word+word1.substr(i);
        }
        if(!word2.empty())
            word = word+word2.substr(i);
        return word;
    }
};
