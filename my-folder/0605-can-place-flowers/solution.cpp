class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = 0;
        if(flowerbed.size() == 1){
            if(!flowerbed[0])
                count++;
            
            return count >= n ? true : false;

        }

        if(!flowerbed[0] && !flowerbed[1]){
            count++;
            flowerbed[0] = 1;
        }
        
        if(!flowerbed[flowerbed.size()-1] && !flowerbed[flowerbed.size()-2]){
            count++;
            flowerbed[flowerbed.size()-1] = 1;
        }
        
        for(int i = 1; i < flowerbed.size() - 1 ; ++i){
            bool adjacencyCheck = (!flowerbed[i-1] && !flowerbed[i+1]);
            cout<<"ith i = "<<i<<" check "<<adjacencyCheck<<endl;
            if(!flowerbed[i] && adjacencyCheck){
                count++;
                flowerbed[i] = 1;
            }
        }
        return count >= n ? true : false;
    }
};
