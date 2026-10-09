class Solution {
public:
    string removeOuterParentheses(string s) {
        int n=s.size();
        string result="";
        int count=0;
        int idx=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') count++;
            else count--;
            if(count==0){
                if(i>idx+1){
                    result+=s.substr(idx+1,i-idx-1);
                }
                idx=i+1;
            }
        }
        return result;
    }
};