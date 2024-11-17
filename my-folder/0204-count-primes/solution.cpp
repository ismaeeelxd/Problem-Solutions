class Solution {
public:
    bitset<5000006> notPrime;
    int cnt =0;
    void sieve(int n){
        notPrime[0] = notPrime[1] = 1;
        for(long long i = 2;i<n;++i){
            if(notPrime[i]) continue;
            else cnt++;
            for(long long j = i*i;j<n;j+=i)
                notPrime[j] = 1;
        }
    }
    int countPrimes(int n) {
        sieve(n);
        return cnt;
    }
};
