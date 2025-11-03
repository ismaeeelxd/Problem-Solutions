class Solution {
public:
    const char c = '1';
    int minCost(string colors, vector<int>& neededTime) {
        if(colors.size() == 1) return 0;

        int i = 0;
        int j = 1;
        int acc = 0;
        while(j < colors.size()) {
            if(colors[i] == c){
                i++;
                continue;
            }
            if(colors[i] == colors[j]) {
                if(neededTime[i] < neededTime[j]) {
                    acc+=neededTime[i];
                } else {
                    acc+=neededTime[j];
                    colors[j]=c;
                    j++;
                    continue;
                }
            }
            i++;
            j++;
        }
        return acc;
    }
};
