class Solution {
public:
    bool judgeCircle(string moves) {
        int total = 0;
        for(const auto& m : moves){
            if(m == 'U') total+=124;
            else if(m == 'D') total-=124;
            else if(m == 'R') total+=341;
            else if(m == 'L') total-=341;
        }

        return total != 0 ? 0 : 1;
    }
};
