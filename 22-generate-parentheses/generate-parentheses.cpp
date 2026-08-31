class Solution {
public:
    void solve(vector<string>& result,int open,int close,string str){
        if(open==0 && close==0){
            result.push_back(str);
            str="";
            return;
        }
        else if(open==close){
            solve(result,open-1,close,str+'(');
        }
        else if(open==0){
            solve(result,open,close-1,str+')');
        }
        // else if(close==0){
        //     string s1=str;
        //     s1+='(';
        //     solve(result,open-1,close,s1);
        // }
        else{
            solve(result,open-1,close,str+'(');
            solve(result,open,close-1,str+')');
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        int open=n;
        int close=n;
        string str="";
        solve(result,open,close,str);
        return result;
    }
};