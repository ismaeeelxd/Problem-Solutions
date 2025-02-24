class Solution {
public:
    bool isValid(int a ,int b, int c){
        if(a + b > c && a + c > b && b + c > a)
            return true;
        return false;
    }
    int largestPerimeter(vector<int>& nums) {
        int i = nums.size()-1;
        sort(nums.begin(),nums.end());
        while(nums.size() >=3 && i > 1){
            int a = nums[i];
            int b = nums[i-1];
            int c = nums[i-2];
            if(isValid(a,b,c)){
                return a + b + c;
            } else {
                nums.pop_back();
                i--;
            }
        }
        return 0;
    }
};
