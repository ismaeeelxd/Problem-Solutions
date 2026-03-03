class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i = 0; i < arr2.size(); ++i) {
            mp[arr2[i]] = i;
        }

        sort(arr1.begin(), arr1.end(), [&] (int a, int b) {
            bool has_a = mp.contains(a);
            bool has_b = mp.contains(b);
            if(!has_a && !has_b) {
                return a < b;
            } else if(has_a && has_b) {
                return mp[a] < mp[b];
            } else {
                return has_a;
            }

        });

        return arr1;
    }
};
