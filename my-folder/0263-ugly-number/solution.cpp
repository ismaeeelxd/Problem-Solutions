class Solution {
public:
    bool isUgly(int n) {
        if(n == 1) return true;
        for(long long i = 2; i * i <= n; ++i){
            while(n % i == 0){
                n/=i;
                cout<<i<<" ";
                if(i != 5 && i != 3 && i != 2) return false;
            }
        }
        if(n != 1){
            if(n != 5 && n != 3 && n != 2) return false;
        }
        return true;
    }
};
