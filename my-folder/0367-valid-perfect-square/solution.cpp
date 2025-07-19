class Solution {
public:
    bool isPerfectSquare(int num) {
    
      for(long long i = 0; i <= num; ++i){
        if(i * i == num) return true;
        if(i*i > num) return false;
      }  
      return 0;
    }
};
