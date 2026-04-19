class Solution {
public:
    int minimumRefill(vector<int>& plants, int capacityA, int capacityB) {
        int n = plants.size();
        int i = 0, j = n - 1;
        
        int currentA = capacityA;
        int currentB = capacityB;
        int refills = 0;
        
        while (i < j) {
            if (currentA < plants[i]) {
                refills++;
                currentA = capacityA; 
            }
            currentA -= plants[i];
            
            // Bob's step
            if (currentB < plants[j]) {
                refills++;
                currentB = capacityB; 
            }
            currentB -= plants[j];
            
            i++;
            j--;
        }
        
        if (i == j) {
            if (max(currentA, currentB) < plants[i]) {
                refills++;
            }
        }
        
        return refills;
    }
};
