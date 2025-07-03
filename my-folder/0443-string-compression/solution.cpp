class Solution {
public:
    int compress(vector<char>& chars) {
        string s = "";
        s.push_back(chars[0]);
        int count = 1;
        for(int i = 1; i < chars.size(); ++i){
            if(chars[i] == chars[i-1]) count++;
            else{
                if(count != 1)
                    s+= to_string(count);
                s.push_back(chars[i]);

                count = 1;
            }
        }
        if(count != 1)
            s+= to_string(count);
    
        chars.clear();
        for(auto &c : s){
            chars.push_back(c);
        }
        return chars.size();
    }
};
