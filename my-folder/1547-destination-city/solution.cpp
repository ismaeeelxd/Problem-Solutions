class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        set<string> out;
        for(size_t i = 0; i < paths.size() ; ++i) {
            out.insert(paths[i][0]);
        }
        for(size_t j = 0; j < paths.size(); ++j){
            if(!out.contains(paths[j][1]))
                return paths[j][1];
        }
        return "";
    }
};
