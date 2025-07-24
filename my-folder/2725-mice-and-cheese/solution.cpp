class Solution {
public:
    static bool compare(const pair<int,int> a, const pair<int,int> b){
        return a.first > b.first;
    }
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        vector<pair<int,int>> res;
        for(int i = 0; i < reward1.size(); ++i){
            res.push_back({ reward1[i] - reward2[i], i});
        }

        sort(res.begin(),res.end(), compare);
        int result = 0;
        for(int i = 0; i < k; ++i){
            int index = res[i].second;
            result+=reward1[index];
        }
        for(int i = k; i < reward1.size(); ++i){
            int index = res[i].second;
            result+=reward2[index];
        }
        return result;
    }
};
