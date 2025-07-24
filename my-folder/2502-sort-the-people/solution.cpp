class Solution {
public:
    static bool compare(const pair<int,string> first, const pair<int,string> second){
        return first.first > second.first;
    }
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int,string>> indexed;
        int i = 0;
        for(const auto&name : names){
            indexed.push_back({heights[i] , name});
            ++i;
        }
        sort(indexed.begin(),indexed.end(), compare);
        vector<string> ans;
        for(const auto & index : indexed){
            ans.push_back(index.second);
        }
        return ans;
    }
};
