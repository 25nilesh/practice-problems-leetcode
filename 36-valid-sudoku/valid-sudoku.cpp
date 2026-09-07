class Solution {
public:
    bool isValid(int row,int col,char d,vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            if(i!=col &&  board[row][i]==d) return false;
            if(i!=row && board[i][col]==d) return false;
        }
        int start_i=(row/3) * 3;
        int start_j=(col/3) * 3;
        for(int k=0;k<3;k++){
            for(int l=0;l<3;l++){
                if(start_i+k==row && start_j+l==col) continue;
                if(board[start_i+k][start_j+l]==d) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board){
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]!='.'){
                    if(!isValid(i,j,board[i][j],board)) return false;
                }
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        return solve(board);
    }
};