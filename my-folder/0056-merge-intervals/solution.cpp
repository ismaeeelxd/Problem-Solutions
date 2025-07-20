class Solution {
public:
    static bool customCompare(const vector<int> &a, const vector<int> &b) {
        return a[0] < b[0];
    }
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>ans;
        sort(intervals.begin(),intervals.end(), this->customCompare);
        for(int i = 0; i < intervals.size(); ++i){
            int start_i = intervals[i][0];
            int end_i = intervals[i][1];
            int ptr = i + 1;
            while(ptr < intervals.size() && end_i >= intervals[ptr][0]){
                end_i = max(end_i,intervals[ptr++][1]);
            }
            vector<int>r;
            i = ptr - 1;
            ans.push_back({start_i,end_i});
        }

        return ans;
    }
};
