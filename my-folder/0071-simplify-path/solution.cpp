class Solution {
public:
    string simplifyPath(string path) {
        stack<string> paths;
        int i = 0;
        while (i < path.size()) {
            string p = "";
            while(i < path.size() && path[i] == '/') ++i;
            while (i < path.size() && path[i] != '/'){ p.push_back(path[i]); ++i;}
            if(p == ".."){
                if(paths.size()) paths.pop();
                continue;
            } 
            if(p == ".") continue;
            if(p.size()) paths.push(p);
            ++i;
        }
        vector<string> v;
        while(!paths.empty()){
            string p = paths.top();
            paths.pop();
            v.push_back(p);
        }
        reverse(v.begin(),v.end());
        string reconstruct = "/";
        for(int i = 0;i < v.size(); ++i) {
            reconstruct+=v[i];
            reconstruct.push_back('/');
        }
        if(reconstruct.size() > 1) reconstruct.pop_back();
        return reconstruct;

    }
};
