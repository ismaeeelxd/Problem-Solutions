class Solution {
public:
    int N;
    vector<vector<int>> g;
    vector<vector<int>> rec(int n){
        if(n == N){
            return {{n}};
        }
        if(!g[n].size()){
            return {{}};
        }
        vector<vector<int>> validFromN;
        for(int i = 0; i < g[n].size(); ++i){
            vector<vector<int>> path = rec(g[n][i]);
            for(int j = 0; j < path.size(); ++j){
                if(path[j].empty()) continue;
                path[j].push_back(n);
                validFromN.push_back(path[j]);
            }
        }

        return validFromN;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        N = graph.size()-1;
        g = graph;
        vector<vector<int>> v = rec(0);
        for(auto& path : v){
            reverse(path.begin(),path.end());
        }
        return v;
    }
};
