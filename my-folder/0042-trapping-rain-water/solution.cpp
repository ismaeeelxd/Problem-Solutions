class Solution {
public:
    int trap(vector<int>& height) {
        vector<int> prefix = { -1 };
        vector<int> suffix = { -1 };

        for(int i = 0; i  < height.size(); ++i) {
            if(height[i] > prefix.back()) prefix.push_back(height[i]);
            else prefix.push_back(prefix.back());
        }

        for(int i = height.size() -1; i >= 0; --i ) {
            if(height[i] > suffix.back()) suffix.push_back(height[i]);
            else suffix.push_back(suffix.back());
        }
        int res = 0;
        for(int i = 1; i < height.size(); ++i) {
            int currentHeight = height[i];
            int pre = prefix[i];
            int suf = suffix[height.size() - 1 - i];
            int min_ = min(pre,suf);
            int diff = min_ - currentHeight;
            if(diff < 0) continue;
            res+=diff;
        }
        return res;

    }
};
