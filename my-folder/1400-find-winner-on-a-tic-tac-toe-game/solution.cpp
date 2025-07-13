class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        int matrix[3][3] = {};
        for (int i = 0; i < moves.size(); ++i) {
            int x, y;
            x = moves[i][0];
            y = moves[i][1];
            matrix[x][y] = i & 1 ? 2 : 1;
        }
        int diagonal_1 = matrix[2][2];
        for (int i = 2, j = 2; i >= 0 && j >= 0; i--, j--) {
            if (matrix[i][j] != diagonal_1){
                diagonal_1 = 0;
                break;
            }
        }

        int diagonal_2 = matrix[1][1];
        for(int i = 0, j = 2; i < 3 && j >= 0; i++, j--){
            if(matrix[i][j] != diagonal_2){
                diagonal_2 = 0;
                break;
            } 
        }
        int rowW = 0;
        for (int i = 0; i < 3; ++i) {
            int row = matrix[i][0];
            for (int j = 0; j < 3; ++j) {
                if(matrix[i][j] != row){
                    row = 0;
                    break;
                }
            }
            rowW += row;
        }

        int colW = 0;
        for(int i = 0; i < 3; ++i){
            int col = matrix[0][i];
            for(int j = 0; j < 3; ++j){
                if(matrix[j][i] != col) col = 0;
            }    
            colW += col;
        }

        cout<<colW << " "<< rowW;
        if(!(colW + rowW + diagonal_1 + diagonal_2)){
            if(moves.size() == 9) return "Draw";
            else return "Pending";
        }
        if(colW == 1 || rowW == 1 || diagonal_1 == 1 || diagonal_2 == 1) return "A";
        if(colW == 2 || rowW == 2 || diagonal_1 == 2 || diagonal_2 == 2) return "B";
        return "A";
    }
};
