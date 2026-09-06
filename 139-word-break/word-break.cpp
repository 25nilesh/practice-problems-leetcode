class Solution {
public:
    int n;
    int dp[301];
    bool solve(int idx,string s,unordered_set<string>& st){
        if(idx==n){
            return true;
        }
        if(st.find(s)!=st.end()) {
            return true;
        }
        if(dp[idx]!=-1) return dp[idx];
        for(int l=1;l<=n;l++){
            string str=s.substr(idx,l);
            if(st.find(str)!=st.end() && solve(idx+l,s,st)){
                return true;
            }
        }
        return dp[idx]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        memset(dp,-1,sizeof(dp));
        n=s.size();
        unordered_set<string> st;
        for(auto str:wordDict){
            st.insert(str);
        }
        return solve(0,s,st);
    }
};