class Solution {
public:
    static bool compare(const pair<int,int> a, const pair<int,int> b){
        return a.first > b.first;
    }

    int twoCitySchedCost(vector<vector<int>>& costs) {
        int n = costs.size() / 2;
        vector<pair<int,int>> diff;
        int i = 0;
        for(auto cost : costs){
            int costA = cost[0];
            int costB = cost[1];
            diff.push_back({ costB - costA, i});
            ++i;
        }
        sort(diff.begin(), diff.end(), compare);
        int res = 0;
        //choose A
        for(int j = 0; j < n; ++j){
            int index = diff[j].second;
            res+=(costs[index][0]);
        }
        for(int j = n; j < costs.size(); ++j){
            int index = diff[j].second;
            res+=(costs[index][1]);
        }
        return res;
    }
};
