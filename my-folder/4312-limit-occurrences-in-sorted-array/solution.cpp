class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {
        vector<int> res;
        for(int i = 0; i < nums.size();) {
            int num = nums[i];
            int kCounter = k;
            
            while(i < nums.size() && nums[i] == num) {
                if(kCounter == 0) {
                    i++;
                    continue;
                }
                res.push_back(num);
                kCounter--;
                i++;
            } 
        }
        return res;
    }
};
