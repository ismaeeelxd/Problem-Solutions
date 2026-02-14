class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        if(nums.size() == 1) return nums; 
        deque<int> l;
        vector<int> res;
        int cntr = 0;
        for (int i = 0; i < nums.size(); ++i) {
            if (i < k) {
                while (l.size() > 0 && nums[i] > l.back()) {
                    l.pop_back();
                }
                l.push_back(nums[i]);
            } else {
               cntr++; 
                cout << l.front() << endl;
                if((i - k) == 0) res.push_back(l.front());
                int toBeRemoved = nums[i - k];

                if (toBeRemoved == l.front()) {
                    l.pop_front();
                }

                while (l.size() > 0 && nums[i] > l.back()) {
                    l.pop_back();
                }
                l.push_back(nums[i]);
                res.push_back(l.front());
            }
        }
        if(!cntr) {
            if(l.size()) return { l.front() };
        }
        return res;
    }
};
