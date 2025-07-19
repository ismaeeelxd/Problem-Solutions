class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
        sort(folder.begin(),folder.end());
        set<string> s;
        for (const auto& path : folder) {
            string p = "";
            int i = 1;
            bool found = false;
            while (i < path.size()) {
                p.push_back('/');
                while (i < path.size() && path[i] != '/') {
                    p.push_back(path[i]);
                    ++i;
                }

                if (s.contains(p)) {
                    // do not add it just skip the whole loop
                    found = true;
                    break;
                }
                ++i;
            }
            if (found)
                continue;
            else {
                s.insert(p);
            }
        }
        return vector<string>(s.begin(), s.end());
    }
};
