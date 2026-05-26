class Solution {
public:
    int numberOfSpecialChars(string word) {
        int cnt = 0;
        int arr[1000] = {0};
        for(char a : word) {
            arr[a]++;
        }
        int start = 'a';
        while(start != 'z' + 1) {
            int end = start - 32;
            cnt+=(arr[start] > 0 && arr[end] > 0 ? 1 : 0);
            start++;
        }
        return cnt;
    }
};
