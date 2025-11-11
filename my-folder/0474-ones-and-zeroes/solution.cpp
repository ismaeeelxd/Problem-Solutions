class Solution {
public:
    vector<string> strs_;
    vector<vector<vector<int>>> memo;
    int m;
    int n;
    int findMax(int index, int ones, int zeroes) {
        if(index >= strs_.size()) return 0;

        auto &ret = this->memo[index][zeroes][ones];
        if(ret != -1) return ret;

        int ones_=0;
        int zeroes_=0;

        for(auto c : strs_[index]) {
            if(c == '1') ones_++;
            else zeroes_++; 
        }
        int skip = findMax(index+1, ones,zeroes);
        if(ones + ones_ > this->n || zeroes + zeroes_ > this->m) {
            //force skip
            return ret=skip;
        } 
        int take = findMax(index+1, ones+ones_, zeroes+zeroes_) + 1;
        return ret= max(skip,take);
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
        this->strs_ = strs;
        this->m = m;
        this->n = n;
        memo.assign(strs.size(), vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
        return findMax(0,0,0);
    }
};
