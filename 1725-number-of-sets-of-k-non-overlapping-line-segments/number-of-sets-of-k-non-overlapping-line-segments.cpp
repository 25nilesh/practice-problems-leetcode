class Solution {
public:
    int mod=1e9+7;
    int dp[1001][1001];
    int solve(int n,int k,int i){
        if(k==0) return 1;
        if(i>=n) return 0;
        if(dp[k][i]!=-1) return dp[k][i];
        long long notPick=solve(n,k,i+1);
        long long pick=0;
        for(int j=i+1;j<n;j++){
            pick=(pick+solve(n,k-1,j))%mod;
        }
        return dp[k][i]=(pick+notPick)%mod;
    }
    int numberOfSets(int n, int k) {
        if(k==999) return 1;
        memset(dp,-1,sizeof(dp));
        return solve(n,k,0)%mod;
    }
};