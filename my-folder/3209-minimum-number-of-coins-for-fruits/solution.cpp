class Solution {
public:
    vector<int> prices;
    int arr[1002][1002];
    int solve(int index, int freeCounter) {
        if(index >= prices.size()) return 0;
        int free = INT_MAX;
        auto &ret = arr[index][freeCounter];
        if(ret != -1) return ret;
        if(freeCounter > 0) {
            free = solve(index+1, freeCounter-1); 
        }

        int buy = solve(index+1, index+1) + prices[index];

        return ret = min(buy,free);

    }
    int minimumCoins(vector<int>& prices) {
        this->prices = prices;
        memset(arr, -1, sizeof(arr));
        return solve(1, 1) + prices[0];
    }
};
