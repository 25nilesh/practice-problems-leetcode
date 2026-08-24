class Solution {
public:
    int n;
    int solve(vector<int>& stones,int i){
        if(i==n-1){
            return stones[i];
        }
        int pick=stones[i]-solve(stones,i+1);
        int notpick=solve(stones,i+1);
        return max(pick,notpick);
    }
    int stoneGameVIII(vector<int>& stones) {
        n=stones.size();
        for(int i=1;i<n;i++){
            stones[i]=stones[i-1]+stones[i];
        }
        // return solve(stones,1);
        vector<int> dp(n,0);
        dp[n-1]=stones[n-1];
        for(int i=n-2;i>=1;i--){
            int take=stones[i]-dp[i+1];
            int not_take=dp[i+1];

            dp[i]=max(take,not_take);
        }
        return dp[1];
    }
};