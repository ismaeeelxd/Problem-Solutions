class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int right = 0;
        set<char> se;
        int maxWindow = 0;
        while(left <= right && right < s.size()){
            if(se.contains(s[right])){
                while(se.contains(s[right])) se.erase(s[left++]);
            }

            se.insert(s[right++]);
            maxWindow = max(maxWindow, right - left);
        }
        return maxWindow;
    }
};
