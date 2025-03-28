class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string merged = "";
        int word1_ptr = 0;
        int word2_ptr = 0;
        int word1_size = word1.size();
        int word2_size = word2.size();
        while(word1_size && word2_size){
            merged+=word1[word1_ptr++];
            merged+=word2[word2_ptr++];
            word1_size--;word2_size--;
        }
        while(word1_size){
            merged+=word1[word1_ptr++];
            word1_size--;
        }
        while(word2_size){
            merged+=word2[word2_ptr++];
            word2_size--;
        }
        return merged;
    }
};
