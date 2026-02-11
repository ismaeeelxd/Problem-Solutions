class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int ptr1 = 0; // 0 
        int ptr2 = k-1; // 2

        multiset<int> set;

        for(int i = ptr1; i <= ptr2; ++i) {
            int num = nums[i];
            set.insert(nums[i]);
        }

        vector<int> res;
        while(ptr2 < nums.size() && ptr1 <= ptr2) {
            int maxNumber = *set.rbegin();
            res.push_back(maxNumber);
            auto it = set.find(nums[ptr1]); // O(log n)
            if (it != set.end()) {
                set.erase(it);        // O(1) amortized
            }
            ptr1++;
            ptr2++;
            if(ptr2 < nums.size()) set.insert(nums[ptr2]);

        }

        return res;
    }
};
