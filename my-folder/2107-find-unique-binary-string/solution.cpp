class Solution {
public:
    vector<string> ans;
    void generate(string s, int n) {
        if(s.size() == n) {
            ans.push_back(s);
            return;
        }
        s.push_back('0');
        generate(s, n);
        s.pop_back();
        s.push_back('1');
        generate(s, n); 
    }
    string findDifferentBinaryString(vector<string>& nums) {
        generate("",nums[0].size());
        sort(ans.begin(), ans.end());
        sort(nums.begin(), nums.end());
        int i = 0;
        for(; i < nums.size(); ++i) {
            if(nums[i] != ans[i]) return ans[i];
        }
        return ans[i];
    }
};
