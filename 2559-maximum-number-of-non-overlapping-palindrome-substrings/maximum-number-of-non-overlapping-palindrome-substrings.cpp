class Solution {
public:
    vector<int> dp;
    vector<vector<bool>> isPalindrome;
    // bool isPalindrome(string str){
    //     int i=0;
    //     int j=str.size()-1;
    //     while(i<=j){
    //         if(str[i]!=str[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    int solve(string s,int k,int i){
        if(i==s.size()){
            return 0;
        }
        if(dp[i]!=-1) return dp[i];
        int ans=solve(s,k,i+1);
        for(int idx=i+k-1;idx<s.size();idx++){
            // string temp=s.substr(i,idx-i+1);
            if(isPalindrome[i][idx]){
                ans=max(ans,1+solve(s,k,idx+1));
            }
        }
        return dp[i]=ans;
    }
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;
        dp.assign(s.size(), -1);
        isPalindrome.assign(n+1,vector<bool>(n+1,false));
        // precomputing all palindromes
        for(int L=1;L<=n;L++){
            for(int i=0;i+L<=n;i++){
                int j=i+L-1;
                if(i==j){
                    isPalindrome[i][j]=true;
                }else if(i+1==j){
                    isPalindrome[i][j]=(s[i]==s[j]);
                }else{
                    isPalindrome[i][j]=((s[i]==s[j]) && isPalindrome[i+1][j-1]);
                }
            }
        }
        return solve(s,k,0);
    }
};