class Solution {
public:
    int dp[21][21];
    int solve(vector<int>& nums,int i,int j){
        if(i>j) return 0;
        if(i==j) return nums[i];
        if(dp[i][j]!=-1) return dp[i][j];

        int pick_i=nums[i]+min(solve(nums,i+2,j),solve(nums,i+1,j-1));
        int pick_j=nums[j]+min(solve(nums,i+1,j-1),solve(nums,i,j-2));

        return dp[i][j]=max(pick_i,pick_j);
    }
    bool stoneGame(vector<int>& piles) {
        return true;
    }
};