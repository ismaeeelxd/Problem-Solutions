class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int x = 0;
        for(auto op : operations) {
            if(op[0] == 'X') {
                if(op[1] == '-') x--;
                else x++;
            } else {
                if(op[0] == '-') {
                    x--;
                } else {
                    x++;
                }
            }
        }
        return x;
    }
};
