class Solution {
public:
string reverseWords(string s) {
    vector<string> t;
    string actualWord="";
    s= s+ ' ';
    for(int i = 0;i<s.size();++i){
        if(s[i] == ' '){
            if(!actualWord.empty())
            t.push_back(actualWord);
            actualWord = "";
            continue;
        }
        else{
            actualWord.push_back(s[i]);
        }
    }
    string sentence;
    for(int i = t.size()-1;i>=0;--i){
        if(i == 0){
            sentence.append(t[0]);
            break;
        }
        else{
            sentence.append(t[i] + " ");
                    }
    }
    return sentence;

}
};
