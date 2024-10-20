class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int k =0;
        for(size_t i = 0;i<nums.size();++i){
            if(nums[i] == val){
                nums[i] = 1e8+2;
                continue;
            }
            k++;
        }
        sort(nums.begin(),nums.end());
        return k;
    }
};
