class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum = 0;
        for(auto & app : apple)sum+=app;
        int ret = 0;
        sort(capacity.begin(),capacity.end());
        for(int i = capacity.size() - 1 ; i >=0; --i) if(sum > 0){
            sum-=capacity[i];
            ret++;
        }
        return ret;
    }
};
