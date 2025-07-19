class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int left = 0;
        int right = n - 1;
        int maxSoFar = -1;
        while(left < right){
            if(height[left] < height[right]){
                maxSoFar = max(maxSoFar, (right - left) * min(height[left],height[right]));
                left++;
            } else {
                maxSoFar = max(maxSoFar, (right - left) * min(height[left],height[right]));
                right--;
            }
        }
        return maxSoFar;
    }
};
