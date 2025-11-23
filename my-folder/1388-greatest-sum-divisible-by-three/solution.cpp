class Solution {
public:
    int maxSumDivThree(vector<int>& nums) {
        vector<int> q_1;
        vector<int> q_2;
        int total = 0;
        for(auto num : nums) {
            total+=num;

            if(num % 3 == 1) q_1.push_back(num);
            if(num % 3 == 2) q_2.push_back(num);
        }
        sort(q_1.begin(), q_1.end());
        sort(q_2.begin(), q_2.end());
        int rem = total % 3;
        if(rem == 0) return total;
        int remove = 0;
        if(rem == 1) {
            int ch1 = INT_MAX;
            int ch2 = INT_MAX;
            if(q_1.size() >= 1) ch1 = q_1[0];
            if(q_2.size() >= 2) ch2 = q_2[0] + q_2[1]; 
            remove = min(ch1, ch2);
        } else {
            int ch1 = INT_MAX;
            int ch2 = INT_MAX;
            if(q_2.size() >= 1) ch1 = q_2[0];
            if(q_1.size() >= 2) ch2 = q_1[0] + q_1[1]; 
            remove = min(ch1, ch2);
        }



        return total - remove;
    }
};
