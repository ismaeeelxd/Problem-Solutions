class Solution {
public:
    int memo[101][101];
    bool isInterleave(string s1, string s2, string s3) {   
        memset(memo,-1,sizeof(memo));
        return solve(s1,s2,s3,0,0);

    }

    bool solve(string &s1, string &s2, string&s3, int idx1,int idx2){
        auto &ret = memo[idx1][idx2];
        if(ret!=-1)
            return ret;
        if(idx1 + idx2  == s3.size()){
            return ret = s1.size() == idx1 && s2.size() == idx2;
        }
        bool cond1 = s1[idx1] == s3[idx1+idx2];
        bool cond2= s2[idx2] == s3[idx1+idx2];

        if(cond1 && cond2){
            return ret= solve(s1,s2,s3,idx1+1,idx2) || solve(s1,s2,s3,idx1,idx2+1);

        }
        if(cond1){
            return ret=   solve(s1,s2,s3,idx1+1,idx2);
        }
        if(cond2){
            return solve(s1,s2,s3,idx1,idx2+1);
        }

        return false;
    }

};
