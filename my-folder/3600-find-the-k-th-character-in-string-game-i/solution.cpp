class Solution {
public:
    char kthCharacter(int k) {
        string word = "a";
        while(word.size() < k){
            string append = "";
            for(int i = 0; i < word.size(); ++i){
                char c = word[i] - 97 + 1;
                c%=26;
                c+=97;
                append.push_back(c);
            }
            word+=append;

        }
        return word[k-1];
    }
};
