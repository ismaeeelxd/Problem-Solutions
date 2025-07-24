class Solution {
public:
    string makeGood(string s) {
        if(s.empty()) return s;
        stack<char> st;
        for(int i = 0; i < s.size(); ++i){
            if(!st.empty() && abs(st.top() - s[i]) == 32) st.pop();
            else st.push(s[i]);
        }
        string ret;
        while(!st.empty()){
            ret.push_back(st.top());
            st.pop();
        }
        reverse(ret.begin(),ret.end());
        return ret; 
    }
};
