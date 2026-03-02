class Solution {
public:
    int bs (int idx, vector<int>& houses, vector<int>& heaters) {
        int left = 0;
        int right = heaters.size() - 1;
        int target = houses[idx];
        int mid = (right - left) / 2;
        // cout << mid << endl;
        while(left <= right) {
            // 1 4 >=
            // 3
            mid = left + (right - left) / 2;

            int heater = heaters[mid];
            if(heater > target) {
                right = mid - 1;
            }
            else if(heater == target) return mid;
            else left = mid+1;
        }
        return left;
    }
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(heaters.begin(), heaters.end());
        sort(houses.begin(), houses.end());
        int radius = INT_MIN;
        for(int i = 0; i < houses.size(); ++i) {
            int idx = bs(i, houses, heaters);
            cout << idx << endl;
            if(idx >= heaters.size()) idx = heaters.size() - 1;
            if(idx <= 0) {
                idx = 0;
                radius = max(abs(houses[i] - heaters[idx]) , radius);
                continue;
            }


            int minR = min(abs(houses[i] - heaters[idx]) , abs(houses[i] - heaters[idx-1]));
            radius = max(radius, minR);
        }
        return radius;
    }
};
