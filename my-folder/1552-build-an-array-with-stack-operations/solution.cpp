class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i = 1;
        const string PUSH = "Push";
        const string POP = "Pop"; 
        vector<string> res;
        int j = 0;
        int cnt = 0;
        while(i != n + 1) {
            if(target[j] != i){
                res.push_back(PUSH);
                cnt++;
            } 
            else {
                while(cnt){
                    res.push_back(POP);
                    cnt--;
                }
                res.push_back(PUSH);
                j++;
            }
            i++;
            if(j == target.size()) break;
        }

        return res;   
    }
};
