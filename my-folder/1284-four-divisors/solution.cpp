class Solution {
public:

    int sumFourDivisors(vector<int>& nums) {
        int sun=0;
        for(int i = 0;i<nums.size();++i){
            int cnt=2;
            int sum=1+nums[i];
            for(int j = 2; j*j<=nums[i];++j){
                if(nums[i] % j == 0){
                    cnt++;
                    sum+=j;
                    if(j != nums[i]/j){
                        cnt++;
                        sum+=nums[i]/j;
                    }
                }
            }
            if(cnt == 4){
                sun+=sum;
            }
        }
        return sun;
    }
};
