class Solution {
public:
    int solve(vector<vector<int>>& img1,vector<vector<int>>& img2,int row,int col){
        int n=img1.size();
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                int nr=i+row;
                int nc=j+col;
                if(nr<0 || nr>=n || nc<0 || nc>=n) continue;
                if(img1[i][j]==1 && img2[nr][nc]==1) cnt++;
            }
        }
        return cnt;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        int ans=INT_MIN;
        for(int i=-n+1;i<n;i++){
            for(int j=-n+1;j<n;j++){
                ans=max(ans,solve(img1,img2,i,j));
            }
        }
        return ans;
    }
};