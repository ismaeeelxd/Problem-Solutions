class Solution {
public:
    string countAndSay(int n) {
        if (n == 1)
            return "1";
        string s = countAndSay(n - 1);
        string ret = "";
        cout<< n << " ";
        for (int i = 0 ; i < s.size();) {
            char a = s[i];
            int count = 0;
            while(i < s.size() && a == s[i]){
                ++i;
                ++count;
            }
            string b = to_string(count);
            ret+=b;
            ret.push_back(a);
        }
        cout << ret << endl;
        return ret;
    }
};
