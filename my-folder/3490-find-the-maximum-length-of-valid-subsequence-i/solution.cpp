class Solution {
public:
    int maximumLength(vector<int>& nums) {
        //odd + odd = even
        //even + even = even
        int odds = 0;
        for(int i = 0; i < nums.size(); ++i) if(nums[i] & 1) odds++;
        int evens = nums.size() - odds;
        // odd + even = odd
        bool odd = nums[0] & 1;
        int seq = 1;
        for(int i = 1; i < nums.size(); ++i){
            if((nums[i] & 1) == !odd){
                seq++;
                odd = !odd;
            }
        }
        int maxN = max(evens,odds);
        return max(maxN,seq);
        
    }
};
