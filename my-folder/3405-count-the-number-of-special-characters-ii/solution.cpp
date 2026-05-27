class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<int> arr(123,-1);
        for(int i = 0; i < word.size(); ++i) {
            if(arr[word[i]] == -1 && isupper(word[i])) arr[word[i]] = i;
            else if(islower(word[i])) arr[word[i]] = i;
        }
        char start = 'A';
        int count = 0;
        while(start != 'Z' + 1) {
            if(arr[start + 32] == -1 || arr[start] == -1) {
                start++;
                continue;
            }
            if(arr[start + 32] < arr[start]) count++;
            start++;
        }
        return count;
    }
};
