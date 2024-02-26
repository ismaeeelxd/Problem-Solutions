class Solution {
public:
   bool isValid(string s) {
    stack<char> arr;
    if (s.size() % 2 != 0) {
        return false;
    }
    for (int i = 0;i<s.size();++i) {
        if (s[i] == '(' || s[i] == '[' || s[i] =='{')
            arr.push(s[i]);
        else if(s[i] ==')') {
            if (i == 0 || arr.empty() || arr.top() != '(')
                return false;
            
            
            arr.pop();
        }
        else if(s[i] == ']') {
                if (i == 0 || arr.empty() || arr.top() != '[')
                    return false;
                arr.pop();
            }
        else if(s[i] == '}') {
                    if (i == 0 || arr.empty() || arr.top() != '{')
                        return false;
                    arr.pop();
                }

    }
    return arr.empty();
}
};




