class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        /*
        * 20 =>  10 + 5 , 5 + 5 + 5
        * 10 =>  5
        /* 5 => take
        */
        vector<int> v(3, 0);
        for (int i = 0; i < bills.size(); ++i) {
            if (bills[i] == 5)
                v[0]++;
            else if (bills[i] == 10) {
                if (v[0] <= 0)
                    return false;

                v[0]--;
                v[1]++;

            } else if (bills[i] == 20) {
                if ((!v[1] && v[0] < 3) || v[1] && !v[0] )
                    return false;
                if (!v[1]) {
                    v[0] -= 3;
                    continue;
                }
                v[1]--;
                v[0]--;
            }
        }

        return true;
    }
};
