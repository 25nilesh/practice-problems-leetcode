class Solution {
public:
    int dp[101][101];
    bool solve(int i,int count,string s){
        if(i==s.size()){
            return count==0;
        }
        if(count<0){
            return false;
        }
        if(dp[i][count]!=-1) {
            return dp[i][count];
        }
        if(s[i]=='('){
            return dp[i][count]=solve(i+1,count+1,s);
        }
        if(s[i]==')'){
            return dp[i][count]=solve(i+1,count-1,s);
        }
        if(s[i]=='*'){
            return dp[i][count]=(solve(i+1,count+1,s) || solve(i+1,count-1,s) || solve(i+1,count,s));
        }
        return dp[i][count]=false;
    }
    bool checkValidString(string s) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s);
    }
};