class Solution {
public:
    int dp[50001];
    int n;
    int solve(vector<int>&nums,int i){
        if(i>=n) return 0;
        if(dp[i]!=-1) return dp[i];
        int result=INT_MIN;

        result=max(result,nums[i]-solve(nums,i+1));

        if(i+1<n) result=max(result,nums[i]+nums[i+1]-solve(nums,i+2));

        if(i+2<n) result=max(result,nums[i]+nums[i+1]+nums[i+2]-solve(nums,i+3));

        return dp[i]=result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n=stoneValue.size();
        memset(dp,-1,sizeof dp);
        int diff=solve(stoneValue,0);
        if(diff>0) return "Alice";
        if(diff<0) return "Bob";
        return "Tie";
    }
};