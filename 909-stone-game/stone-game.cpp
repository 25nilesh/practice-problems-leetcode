class Solution {
public:
    int dp[501][501];
    int solve(vector<int>& nums,int i,int j){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];

        int pick_i=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int pick_j=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));

        return dp[i][j]=max(pick_i,pick_j);
    }
    bool stoneGame(vector<int>& piles) {
        int n=piles.size();
        memset(dp,-1,sizeof dp);
        int total_sum=accumulate(piles.begin(),piles.end(),0);
        int player1=solve(piles,0,n-1);
        int player2=total_sum-player1;
        return player1>=player2;
    }
};