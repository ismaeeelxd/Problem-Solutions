class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        set<int> s;
        for(int i = 0; i < nums.size(); ++i){
            s.insert(nums[i]);
        }
        int counter = 1;
        for(int i = 0;;++i){
            if(!s.contains(counter)) return counter;
            else counter*=2;
        }
        return 0;
    }
};
