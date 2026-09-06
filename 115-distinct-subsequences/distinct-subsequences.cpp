class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string& s,string& t){
        if(j==t.size()) return 1;
        if(i==s.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s[i]==t[j]){
            return dp[i][j]=solve(i+1,j+1,s,t)+solve(i+1,j,s,t);
        }else{
            return dp[i][j]=solve(i+1,j,s,t);
        }
    }
    int solve1(int n,int m,string& s,string& t){
        if(m<0) return 1;
        if(n<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        if(s[n]==t[m]){
            return dp[n][m]=solve1(n-1,m-1,s,t)+solve1(n-1,m,s,t);
        }else{
            return dp[n][m]=solve1(n-1,m,s,t);
        }
    }
    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        // return solve(0,0,s,t);
        int n=s.size();
        int m=t.size();
        return solve1(n-1,m-1,s,t);
    }
};