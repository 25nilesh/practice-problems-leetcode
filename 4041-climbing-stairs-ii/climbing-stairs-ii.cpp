class Solution {
public:
    int dp[100000+1];
    int solve(int n,vector<int>& costs){
        if(n==0) return 0;
        if(n<0) return INT_MAX;
        if(dp[n]!=-1) return dp[n];
        int jump1=solve(n-1,costs);
        int jump2=solve(n-2,costs);
        int jump3=solve(n-3,costs);
        int ans=INT_MAX;
        if(jump1!=INT_MAX){
            ans=min(ans,jump1+costs[n-1]+1);
        }
        if(jump2!=INT_MAX){
            ans=min(ans,jump2+costs[n-1]+4);
        }
        if(jump3!=INT_MAX){
            ans=min(ans,jump3+costs[n-1]+9);
        }
        return dp[n]=ans;
    }
    int climbStairs(int n, vector<int>& costs) {
        memset(dp,-1,sizeof(dp));
        return solve(n,costs);
    }
};