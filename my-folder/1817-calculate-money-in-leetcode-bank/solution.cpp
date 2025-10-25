class Solution {
public:
    int totalMoney(int n) {
        int res = 0;
        int last = 1;
        int currCounter = last;
        for(int i = 0; i < n; ++i) {
            if(i % 7 == 0){
                res+=last;
                last++;
                currCounter = last;
                continue;
            } 
            res+=currCounter;
            currCounter++;
        }
        return res;
    }
};
