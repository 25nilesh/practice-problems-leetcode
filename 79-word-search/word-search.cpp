class Solution {
public:
    int m,n;
    vector<vector<int>> directions={{-1,0},{1,0},{0,-1},{0,1}};
    bool solve(int r,int c,int i,vector<vector<char>>& board,string& word){
        if(i==word.size()) return true;
        if(r<0 || c<0 || r>=m || c>=n) return false;
        char temp = board[r][c];
        board[r][c]='#';
        for(auto& dir: directions){
            int nr=r+dir[0];
            int nc=c+dir[1];
            if(nr<0 || nc<0 || nr>=m || nc>=n) continue;
            if(board[nr][nc]!=word[i]) continue;
            if(solve(nr,nc,i+1,board,word)){
                // board[r][c]=temp;
                return true;
            }
        }
        board[r][c] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m=board.size();
        n=board[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j]==word[0]){
                    if(solve(i,j,1,board,word)) return true;
                }
            }
        }
        return false;
    }
};