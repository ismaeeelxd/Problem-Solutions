class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        unordered_map<int,int> map;
        for(const auto& num : nums) map[num]++;
    
        for(const auto&[value,freq] : map){
            bool prime = 1;
            if(freq < 2) continue;
            if(freq == 2) return prime;
            for(int i = 2; i * i <= freq; ++i){
                if(freq % i == 0) prime=0;
            }
            if(prime) return prime;
        }
        return false;
    }
};
