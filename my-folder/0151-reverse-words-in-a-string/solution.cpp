class Solution {
public:
string reverseWords(string s) {
    if(s == "")
        return s;
    int n = s.size();
    int i=0;
    int j=0;
    while(j < n){
        while(j < n && s[j] == ' ') j++;
        while(j < n && s[j] != ' ') s[i++] = s[j++];
        if(j < n) s[i++] = ' ';
    }

    if (i > 0 && s[i-1] == ' ')
        i--;

    s.resize(i);
    int right = s.size()-1;
    int left = 0;
    while(left < right){
        char temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }

    i = 0;
    while(i < s.size()){
        int j = i;
        while(s[j] != ' ' && j < s.size()) ++j;
        int in = j;
        j--;
        while(i<j){
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
            ++i;
            --j;
        }
        i = in+1;
    }


    return s;

}

};
