class Solution {
public:
    string sortVowels(string s) {
        set<char> vowels = { 'A', 'E', 'I', 'O', 'U', 'a', 'e', 'i', 'o', 'u'};
        map<char,int> vowelsOcc;
        string t = "";

        for(auto c : s) {
            if(vowels.contains(c)) vowelsOcc[c]++;
        }

        for(auto c : s) {
            if(!vowels.contains(c)) {
                t.push_back(c);
            } else {
                for(auto v : vowels) {
                    if(vowelsOcc[v] > 0) {
                        t.push_back(v); 
                        vowelsOcc[v]--;
                        break;
                    }
                }
            } 
        }

        return t;
    }
};
