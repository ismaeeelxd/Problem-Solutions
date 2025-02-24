class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        vector<vector<int>> ret;
        int minAbs = 1e8;
        for(int i = 0;i<arr.size()-1;++i){
            if(abs(arr[i+1] - arr[i])  < minAbs){
                minAbs = abs(arr[i+1] - arr[i]);
            }
        }
        for(int i = 0;i<arr.size()-1;++i){
            if(abs(arr[i+1] - arr[i]) == minAbs){
                vector<int> pair;
                pair.push_back(arr[i]);
                pair.push_back(arr[i+1]);
                ret.push_back(pair);
            }
        }
        return ret;
    }

};
