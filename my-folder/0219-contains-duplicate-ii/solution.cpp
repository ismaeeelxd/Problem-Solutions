class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(k >= nums.size()){
            set<int> s;
            for(auto x : nums){
                if(s.contains(x)) return true;
                s.insert(x);
            }
            return false;
        }

        
        set<int> s;
        int i = 0;
        int a = k;
        deque<int> dq;
        while (a--) {
            if (s.contains(nums[i]))
                return true;
            s.insert(nums[i]);
            dq.push_back(nums[i]);
            ++i;
        }


        while (i < nums.size()) {
            if(s.contains(nums[i])) return true;
            dq.push_back(nums[i]);
            s.insert(nums[i]);
            s.erase(dq.front());
            dq.pop_front();
            ++i;
        }

        return false;
    }
};
