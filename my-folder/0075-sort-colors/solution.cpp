class Solution {
public:
    void sortColors(vector<int>& nums) {
        if(nums.size() == 0) return;
        int nextPlace = 0;

            for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == 0) {
                swap(nums[i], nums[nextPlace]);
                nextPlace++;
                while (nextPlace < nums.size() && nums[nextPlace] == 0)
                    nextPlace++;
                i = nextPlace - 1;
                if(nextPlace >= nums.size()) break;
            }
        }
        
        for (int i = nextPlace; i < nums.size(); ++i) {
            if (nums[i] == 1) {
                swap(nums[i], nums[nextPlace]);
                nextPlace++;
                while (nextPlace < nums.size() && nums[nextPlace] == 1)
                    nextPlace++;
                    i = nextPlace - 1;

                    if(nextPlace >= nums.size()) break;

            }
        }
    }
};
