class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = 1;
        if(s == ""){
            return 0;
        }
        for(int i = 0;i<s.size();++i){
            unordered_map<char,int>arr;
            int l = 0;
            for(int j = i;j<s.size();++j){
                if(!arr[s[j]]){
                    arr[s[j]]=1;
                    l++;
                    if(len < l)
                        len = l;
                } else {
                    if(len < l)
                        len = l;
                    break;
                }
            }
        }
        return len;
    }
};
