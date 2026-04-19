class Solution {
public:
    string customSortString(string order, string s) {
        int arr[27] = {0};
        const char a = 'a';
        for (auto& x : s) {
            arr[x - a]++;
        }
        int i = 0;
        for (int k = 0; k < order.size(); ++k) {
            while (i < s.size() && k < order.size() && arr[(order[k] - a)] != 0) {
                s[i] = order[k];
                arr[order[k] - a]--;
                i++;
            }
        }
        for (int j = 'a'; j <= 'z'; ++j) {
            while (i < s.size() && arr[j - a] != 0) {
                s[i] = (char)(j);
                arr[j - a]--;
                i++;
            }
        }
        return s;
    }
};
