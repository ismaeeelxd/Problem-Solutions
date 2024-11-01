class Solution {
public:
    int romanToInt(string s) {
        std::unordered_map<char, int> romanValues = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };
        int sum = 0;
        bool x = 0;
        for(int i = 0;i<s.size();++i){
            if(x){
                x=0;
                continue;
            }
            if(i+1 != s.size() && romanValues[s[i]] < romanValues[s[i+1]]){
                sum+=(romanValues[s[i+1]] - romanValues[s[i]]);
                x=1;
                continue;
            }
            sum+=romanValues[s[i]];
        }
        return sum;
    }
};
