class Solution {
public:
    vector<string> results;
    bool isValid(string &res) {
        const int closed = ')';
        const int opened = '(';
        if(res[0] == closed) return false;
        stack<int> c;
        int i = 0;
        while(i < res.size()) {
            if(res[i++] == opened) c.push(opened);
            else {
                if(c.empty()) return false;
                else c.pop();
            }
        }
        return c.empty();
    }
    void generate(string &res, int n) {
        if(res.size() == n * 2) {
            if(isValid(res)) this->results.push_back(res);
            return;
        }
        const char closed = ')';
        const char opened = '(';

        res.push_back(opened);
        generate(res, n);
        res.pop_back();
        res.push_back(closed);
        generate(res, n);
        res.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string res = "";
        generate(res, n);
        return this->results;
    }
};
