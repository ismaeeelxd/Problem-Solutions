class Solution {
public:
    string months[12]{"Jan", "Feb", "Mar", "Apr", "May", "Jun", "Jul", "Aug", "Sep", "Oct", "Nov", "Dec"};
    vector<string> breakWhiteSpace(string str) {
        int index = 0;
        string build = "";
        vector<string> v;
        str.push_back(' ');
        while(index < str.size()) {
            if(str[index] == ' ') {
                v.push_back(build);
                build.clear();
                index++;
                continue; 
            }
            build.push_back(str[index++]);
        }
        return v;
    }
    string reformatDate(string date) {
        vector<string> parts = breakWhiteSpace(date);
        string reform = "";
        for(int i = 0; i < 4; ++i)
            reform.push_back(parts[2][i]);
        reform.push_back('-');
        int mo = -1;
        for(int i = 0; i < 12; ++i) {
            if(months[i] == parts[1]) {
                mo = i + 1;
                break;
            } 
        }
        string month = to_string(mo);
        if(month.size() == 1) {
            reform.push_back('0');
            reform.push_back(month[0]);
        } else {
            reform.push_back(month[0]);
            reform.push_back(month[1]);

        }
        reform.push_back('-');
        string day = parts[0].substr(0,2);
        if(!isdigit(day[1])) {
            day[1] = day[0];
            day[0] = '0';
        }
        reform.push_back(day[0]);
        reform.push_back(day[1]);

        return reform;

    }
};
