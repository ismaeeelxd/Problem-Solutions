class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res;
        for(int i = 0; i <= n; ++i) {
            int n = i;
            int counter = 0;
            for(int i = 0; i < 31; ++i) {
                if(n & 1) counter++;
                n = n >> 1;
            }
            if(n & 1) counter++;
            res.push_back(counter);
        }
        return res;
    }
};
