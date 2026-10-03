class Solution {
public:
    int longestValidParentheses(string s) {
        int open=0;
        int close=0;
        int result=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                open++;
            }else{
                close++;
            }
            if(open==close){
                result=max(result,open+close);
            }
            if(close>open){
                open=0;
                close=0;
                continue;
            }
        }
        open=0; 
        close=0;
        for(int i=n-1;i>=0;i--){
            if(s[i]==')'){
                close++;
            }else{
                open++;
            }
            if(open==close){
                result=max(result,open+close);
            }
            if(open>close){
                open=0;
                close=0;
                continue;
            }
        }
        return result;
    }
};