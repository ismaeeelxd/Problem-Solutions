class Solution {
public:
    int maxArea(vector<int>& height) {
        int ptr1 = 0;
        int ptr2 = height.size() - 1;
        int maxSoFar = INT_MIN;
        while(ptr1 < ptr2) {
            int width = ptr2-ptr1;
            int num1 = height[ptr1];
            int num2 = height[ptr2];
            int min_ = min(num1, num2);
            maxSoFar = max(min_ * width, maxSoFar);
            if(num1 < num2) ptr1++;
            else ptr2--;
        }

        return maxSoFar;
    }
};
