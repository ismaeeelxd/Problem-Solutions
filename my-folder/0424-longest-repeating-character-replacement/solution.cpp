class Solution {
public:
    int characterReplacement(string s, int k) {
        char character_array[26];
        character_array[0] = 'A';
        for (int i = 1; i < 26; ++i) {
            character_array[i] = character_array[i - 1] + 1;
        }
        int ret = 0;
        for (int i = 0; i < 26; ++i) {
            int kCounter = k;
            int ptr1 = 0;
            int ptr2 = 0;
            int currentCharacter = character_array[i];
            // ABAA
            // ptr1 = 0
            /*
                ptr1 = 1 B
                ptr2 = 1 B

            */
            while(ptr1 <= ptr2 && ptr2 < s.size()) {

                if(s[ptr2] != currentCharacter) {
                    kCounter--;
                    if(kCounter < 0) {
                        while(ptr1 < s.size() && s[ptr1] == currentCharacter) ptr1++;
                        ptr1++;
                        if(ptr1 >= ptr2) ptr2 = ptr1;
                    }
                }
                if(ptr2 >= s.size()) break;
                ret = max(ret, ptr2 - ptr1 + 1);
                ptr2++;
            }
            ret = max(ret, ptr2 - ptr1);
        }
        return ret;
    }
};
