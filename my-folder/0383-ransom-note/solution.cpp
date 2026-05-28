class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int ransomNoteArr[128] = {0};
        int magazineArr[128] = {0};
        for(int i = 0; i < ransomNote.size(); ++i) {
            ransomNoteArr[ransomNote[i]]++;
        }
        for(int i = 0; i < magazine.size(); ++i) {
            magazineArr[magazine[i]]++;
        }
        for(int i = 0; i < 128; ++i) {
            if(magazineArr[i] < ransomNoteArr[i]) return false;
        }
        return true;

    }
};
