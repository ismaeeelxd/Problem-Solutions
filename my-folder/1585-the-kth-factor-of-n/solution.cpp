class Solution {
public:
    int kthFactor(int n, int k) {
        int count = 0;
        int num = 1;
        while(num <= n){
            if(n % num == 0){
                count++;
                if(count == k) return num;
            }
            num++;
        }
        return -1; 
    }
};
