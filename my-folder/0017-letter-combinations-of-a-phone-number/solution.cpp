class Solution {
public:
    string dic[9] = {
        "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz",
    };
    vector<string> res;
    string digits;
    void solve(int index, string a) {
        if(index == this->digits.size()) {
            res.push_back(a);
            return;
        }
        int j = this->digits[index] - '0' - 1;
        string b = dic[this->digits[index] - '0' - 1];
        for(int i = 0; i < b.size(); ++i) {
            solve(index + 1, a + b[i]);
        }
    }

    vector<string> letterCombinations(string digits) {
        this->digits = digits;
        solve(0,"");
        return this->res;
    }
};
