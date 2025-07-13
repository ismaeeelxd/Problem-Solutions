class Solution {
public:
    int arraySign(vector<int>& nums) {
        int negatives = 0;
        for(const auto &num : nums){
            if(num == 0)
                return 0;
            if(num < 0) negatives++;
        }
        if(negatives % 2 == 0) return 1;
        return -1;
    }
};
