class Solution {
public:
    bool isValid(string word) {
        int upper = 0;
        int lower = 0;
        bool vowel = false;
        bool cons = false;
        bool digit = false;
        char vowels[] = {'a','e','i','o','u' , 'A', 'E', 'I','O','U'};
        for(int i = 0; i < word.size(); ++i){
            bool isVowel = false;
            if(isalpha(word[i])){
                if(islower(word[i])) lower++;
                else upper++;
                for(char &a : vowels) if(a == word[i]) isVowel = true;
                if(!isVowel) cons = true;
                else vowel = true;
            } else if(isdigit(word[i])) digit = true;
            else return false;
        }
        bool check = vowel && cons && word.size() > 2;
        if(check) return true;
        return false;
    }
};
