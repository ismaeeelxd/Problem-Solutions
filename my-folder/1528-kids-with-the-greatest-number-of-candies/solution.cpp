class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int n = candies.size();
        int maxCandy = INT_MIN;
        for(int i = 0;i<n;++i){
            maxCandy = max(candies[i], maxCandy);
        }
        vector<bool> res;
        for(int i = 0;i<n;++i){
            if(candies[i] + extraCandies >= maxCandy)
                res.push_back(true);
            else res.push_back(false);
        }
        return res;
    }
};
