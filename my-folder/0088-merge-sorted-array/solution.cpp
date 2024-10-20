class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int lidx = m-1;
        int nums2idx = n-1;
        int lastIdx = m+n-1;
        while(nums2idx >= 0){
            if(lidx >= 0 && nums1[lidx] > nums2[nums2idx]){
                nums1[lastIdx] = nums1[lidx];
                lidx--;
            } else {
                nums1[lastIdx] = nums2[nums2idx];
                nums2idx--;
            }
            lastIdx--;

        }


    }
};
