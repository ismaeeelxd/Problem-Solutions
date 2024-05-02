class Solution {
public:
    bool isAnagram(string s, string t) {
        int arr[123];
        int arr2[123];
        for(int i = 0;i<s.size();++i)
           arr[s[i]]++; 
        for(int i = 0;i<t.size();++i)
            arr2[t[i]]++;
        for(int i = 97;i<=122;++i)
            if(arr[i] !=arr2[i])
                return false;
        
        return true;
    }
};
