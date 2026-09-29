class Solution {
public:
    int dp[101][101][201];
    bool solve(int i,int j,int m,int n,int cnt,vector<vector<char>>& grid){
        cnt+= (grid[i][j]=='(') ? 1 : -1;
        if(cnt<0) return false;

        if(i==m-1 && j==n-1){
            return cnt==0;
        }
        if(dp[i][j][cnt]!=-1) return dp[i][j][cnt];
        bool result=false;
        // down 
        if(i+1<m){
            if(solve(i+1,j,m,n,cnt,grid)) result=true;
        }
        // right
        if(j+1<n){
            if(solve(i,j+1,m,n,cnt,grid)) result=true;
        }
        return dp[i][j][cnt]=result;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if(grid[0][0]==')') return false;
        if((m+n-1) & 1) return false; 
        memset(dp,-1,sizeof(dp));
        return solve(0,0,m,n,0,grid);
    }
};