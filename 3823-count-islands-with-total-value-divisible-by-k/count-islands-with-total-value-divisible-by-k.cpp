class Solution {
public:
    int dir[4][2]={{0,1},{1,0},{-1,0},{0,-1}};
    long long dfs(vector<vector<int>>& grid,int i,int j){

        int m = grid.size();
        int n = grid[0].size();
        long long sum=grid[i][j];
        grid[i][j]=0;
        for(auto d:dir){
            int nr=i+d[0];
            int nc=j+d[1];
            if (nr >= 0 && nr < m && nc >= 0 && nc < n && grid[nr][nc]>0) {
                sum+=dfs(grid,nr,nc);
            }
        }
        return sum;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        int count=0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]>0) {
                    long long sumOfIsland=dfs(grid,i,j);
                    if(sumOfIsland%k==0) count++;
                }
            }
        }
        return count;
    }
};