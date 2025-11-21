class Solution {
public:
    int countPalindromicSubsequence(string s) {
        unordered_map<char, vector<int>> mp;
        for(auto &c : s) {
            mp[c] = { -1, -1 };
        }
        size_t n = s.size();  
        unordered_map<char,bool> seen;
        vector<int> arr(n,0);
        arr[0] = 0;
        seen[s[0]] = true;

        for(size_t i = 1; i < n; ++i) {
            char c = s[i];
            if(seen[c]) {
                arr[i] = arr[i-1] + 1;
            } else arr[i] = arr[i-1];
            seen[c] = true;
        } 

        for(size_t i = 0; i < n; ++i) {
            char c = s[i];
            vector<int> &v = mp[c];
            if(v[0] == -1) {
                v[0] = i;
            } else {
                v[1] = i;
            }
        }
        int count = 0;
        for(auto &[letter, v] : mp) {
            int i = v[0];
            int j = v[1];
            if(i != -1 && j != -1) {
                int dups = 0;
                bool arr[26] = {0};
                for(size_t k = i+1; k <= j-1; ++k) {
                    int index = s[k] - 'a';
                    if(arr[index] == true) {
                        dups++;
                    } else arr[index] = true;
                }
                count+=(j - i - 1) - dups;
            }
        }

        return count;
    }
};
