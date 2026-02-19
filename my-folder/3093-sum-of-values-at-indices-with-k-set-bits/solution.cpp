class Solution {
public:
    int sumIndicesWithKSetBits(vector<int>& nums, int k) {
        int arr[1001];
        for(int i = 0; i <= 1000; ++i) {
            int index = i;
            int counter = 0;
            for(int j = 0; j < 31; ++j) {
                if(i & 1) counter++;
                i = i >> 1;
            }
            if(i&1) counter++;
            arr[index] = counter;
            i = index;
        }
        int sum = 0;
        for(int i = 0; i < nums.size(); ++i) {
            if(arr[i] == k) {
                sum+=nums[i];
            }
        }
        return sum;
    }
};
