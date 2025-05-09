class Solution {
public:
    ;
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> answer(numRows);
        answer[0].resize(1);
        answer[0][0] = 1;
        for(int i = 1;i < numRows;++i){
            answer[i].resize(i+1);
            answer[i][0] = 1;
            answer[i][i] = 1;
            for(int j = 1; j < i; ++j)
                answer[i][j] = answer[i-1][j-1] + answer[i-1][j];
        }
        return answer;
    }

    void formRow(vector<vector<int>> &answer,int numRows){
        answer[numRows-1].resize(numRows);
        if(numRows == 1){
            answer[0][0] = 1;
            return;
        }

        answer[numRows-1][0] = 1;
        answer[numRows-1][numRows-1] = 1;
        
        formRow(answer,numRows-1);

        for(int i = 1; i< numRows - 1; ++i){
            answer[numRows-1][i] = answer[numRows-2][i-1] + answer[numRows-2][i];
        }

    }

    
};
