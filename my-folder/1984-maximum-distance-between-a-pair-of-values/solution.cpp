class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int max_ = -1;
        for (int i = 0; i < nums1.size(); ++i) {
            int target = nums1[i];
            auto it = std::lower_bound(nums2.rbegin(), nums2.rend() - (i + 1), target);
            if (it != nums2.rend()) {
                int index = std::distance(it, nums2.rend()) - 1;
                max_ = max(max_, index - i);
            } else {
                continue;
            }
        }
        return max_;
    }
};
