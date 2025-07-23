class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        unordered_map<int,int> s;
        int n = -1;
        for(const auto&num : nums) s[num]++;
        for(const auto&num : nums){
            if(s[num] >= 2){
                if(n == -1){
                    n = num;
                    s.erase(num);
                } else {
                    s.erase(num);
                    n^=num;
                }
            }
        }

        return n != -1 ? n : 0;
    }
};
