class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int memo[205][205];
        memset(memo,-1,sizeof(memo));
        return solve(triangle,0,0,memo);
    }

    int solve(vector<vector<int>>& triangle, int i, int row,int(&memo)[205][205]){
        if(row == triangle.size()-1){
            return triangle[row][i];
        }
        auto &ret = memo[i][row];
        if(ret!=-1)
            return ret;
        int choice_1 = solve(triangle,i+1,row+1,memo);
        int choice_2 = solve(triangle,i,row+1,memo);
        int mini = min(choice_1,choice_2);
        return ret = mini + triangle[row][i];
    }
};
