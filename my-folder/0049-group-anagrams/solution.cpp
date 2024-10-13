class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> anagrams{};
        unordered_map<string,int> savedtotals;
        for(string &x : strs){
                string a = x;
                sort(x.begin(),x.end());
                if(savedtotals[x]){
                    anagrams[savedtotals[x]-1].push_back(a);
                } else {
                    savedtotals[x] = anagrams.size()+1;
                    vector<string> t {a};
                    anagrams.push_back(t);
                }
            }        
            return anagrams;
    }
};
