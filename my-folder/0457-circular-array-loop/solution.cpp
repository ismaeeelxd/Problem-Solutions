class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();
        int iter = 1;
        unordered_map<int,int> mp; 

        for(int i = 0; i < n; ++i) {
            bool cur_dir = nums[i] >= 0 ? true : false;
            int cur_idx = i;

            if(mp.contains(cur_idx)) continue;
            mp[cur_idx] = iter;
            int nextIdx = (((cur_idx + nums[cur_idx]) % n)  + n) % n;
            cur_idx = nextIdx;
            while(true) {
                bool dir = nums[cur_idx] >= 0 ? true : false;
                if(dir != cur_dir) {
                    break;
                }
                if(mp.contains(cur_idx) && mp[cur_idx] != iter) break;

                nextIdx =  (((cur_idx + nums[cur_idx]) % n)  + n) % n;
                if(mp[cur_idx] == iter){
                    if(nextIdx == cur_idx) break;
                    return true;
                } 
                mp[cur_idx] = iter;
                cout << nextIdx << endl;
                cur_idx = nextIdx;
            }

            iter++;

        }
        return false;
    }
};
