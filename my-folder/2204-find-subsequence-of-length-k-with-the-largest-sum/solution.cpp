class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> pairs;
        for (int i = 0; i < nums.size(); ++i) {
            pairs.emplace_back(nums[i], i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
        for (const auto& pair : pairs) {
            pq.push(pair);
            if (pq.size() > k)
                pq.pop();
        }
        vector<pair<int, int>> vq;
        while (!pq.empty()) {
            vq.push_back(pq.top());
            pq.pop();
        }
        sort(vq.begin(), vq.end(),
             [](const pair<int, int>& a, const pair<int, int>& b) {
                 return a.second < b.second;
             });
        vector<int> result;
        for (auto& p : vq)
            result.push_back(p.first);
        return result;
    }
};
