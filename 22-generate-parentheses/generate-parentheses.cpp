class Solution {
public:
    void solve(int n,int open,int close,string curr,vector<string>& result){
        if(close==n){
            result.push_back(curr);
            curr="";
            return;
        }
        if(open<n) solve(n,open+1,close,curr+'(',result);
        if(close<open) solve(n,open,close+1,curr+')',result);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string curr="";
        solve(n,0,0,curr,result);
        return result;
    }
};