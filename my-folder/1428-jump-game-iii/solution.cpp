class Solution {
public:
    int memo[100001];
    bool visited[100001];
    bool dp(int i, vector<int> &arr){
        if(i >= arr.size() || i < 0 || visited[i]) return false;
        if(arr[i] == 0) return true;
        auto&ret = memo[i];
        if(ret != -1) return ret;
        visited[i] = true;
        return ret = dp(i + arr[i], arr) || dp(i - arr[i], arr);

    }
    bool canReach(vector<int>& arr, int start) {
        memset(memo,-1,sizeof(memo));
        return dp(start,arr);
    }
};
