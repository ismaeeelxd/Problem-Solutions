class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        // [i][0]
        int m = matrix.size();    // rows // 1
        int n = matrix[0].size(); // cols // 1
        int low = 0;
        int high = m - 1; // 0
        int floor = 0;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            int num = matrix[mid][0];
            if (num > target) {
                high = mid - 1;
            } else if (num == target)
                return true;
            else {
                low = mid + 1;
                floor = mid;
            }
                
        }

        int lowRow = 0;
        int highRow = n - 1;

        while (lowRow <= highRow) {
            int mid = lowRow + (highRow - lowRow) / 2;
            int num = matrix[floor][mid];
            if (num > target) {
                highRow = mid - 1;
            } else if (num == target)
                return true;
            else
                lowRow = mid + 1;
        }


        return false;
    }
};
