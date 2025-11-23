class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> heights_ = heights;
        sort(heights.begin(), heights.end());
        int err = 0;
        for(int i = 0; i < heights.size(); ++i) {
            if(heights[i] != heights_[i]) err++;
        }
        return err;
        
    }
};
