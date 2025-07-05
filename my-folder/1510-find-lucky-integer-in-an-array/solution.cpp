class Solution {
public:
    int findLucky(vector<int>& arr) {
        int freq[502] = {};
        int ret = -1;
        for(int i = 0; i < arr.size(); ++i) freq[arr[i]]++;
        for(int i = 0; i < arr.size(); ++i) if(freq[arr[i]] == arr[i] && arr[i] > ret) ret = arr[i];
        return ret;
    }
};
