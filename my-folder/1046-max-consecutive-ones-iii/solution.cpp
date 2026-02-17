class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        deque<int> dq;
        int kCounter = k;
        int max_ = INT_MIN;
        for(int i = 0; i < nums.size(); ++i) { 
            if(nums[i] == 0) {
                if(kCounter == 0) {
                    while(dq.size() && dq.front() == 1) dq.pop_front();
                    if(dq.size()) dq.pop_front();
                    else continue;
                } else kCounter--;
            } 
            dq.push_back(nums[i]);
            max_ = max(max_, (int)dq.size());
        }
        return max(max_, (int)dq.size()) ;
    }
};
