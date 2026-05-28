class Solution {
public:
    int passwordStrength(string password) {
        set<char> acc = {'!', '@', '#', '$'};
        set<char> occ;
        int total_points = 0;
        for(int i = 0; i < password.size(); ++i) {
            if(occ.contains(password[i])) continue;
            occ.insert(password[i]);
            if(islower(password[i])) {
                total_points++;
            } else if(isupper(password[i])) {
                total_points+=2;
            } else if(isdigit(password[i])) {
                total_points+=3;
            } else if(acc.contains(password[i])) {
                total_points+=5;
            }
        }

        return total_points;
    }
};
