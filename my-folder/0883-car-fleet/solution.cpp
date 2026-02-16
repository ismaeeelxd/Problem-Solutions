class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        if(position.size() == 1) return 1;
        vector<pair<int,int>> v(position.size());
        for(int i = 0; i < position.size(); ++i) {
            v[i] = { position[i], speed[i] };
        }
        sort(v.begin(), v.end(), [&](const pair<int,int> a, const pair<int,int> b) {
            return a.first < b.first;
        });

        vector<float> reachesIn;

        for(int i = 0; i < position.size(); ++i) {
            int initialPosition = v[i].first;
            int speed = v[i].second;
            float time = (float)(target - initialPosition) / speed;
            while(reachesIn.size() && time >= reachesIn.back()) reachesIn.pop_back();
            reachesIn.push_back(time);
        }
        return reachesIn.size();    
        }
};
