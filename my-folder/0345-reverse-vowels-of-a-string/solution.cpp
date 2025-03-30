class Solution {
public:
    string reverseVowels(string s) {
        string vowels = "";
        for(int i = 0;i<s.size();++i){
            bool isVowel = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'; 
            if(isVowel)
                vowels.push_back(s[i]);
        }
        int left = 0;
        int right = vowels.size() - 1;
        while(left < right){
            int temp = vowels[left];
            vowels[left] = vowels[right];
            vowels[right] = temp;
            left++;
            right--;
        }
        cout<<vowels;
        int vowelPtr = 0;
        for(int i = 0;i<s.size();++i){
            bool isVowel = s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U'; 
            if(isVowel){
                s[i] = vowels[vowelPtr];
                vowelPtr++;
            }
        }
        return s;
    }
};
