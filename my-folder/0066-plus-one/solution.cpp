class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        n--;
        digits[n]++;
        for(int i = n; i > 0; --i){
            if(digits[i] == 10){
                digits[i] = 0;
                digits[i-1]++;
            }
        }
        if(digits[0] == 10){
            digits.push_back(0);
            digits[0] = 1;
        }
        return digits;
    }
};
