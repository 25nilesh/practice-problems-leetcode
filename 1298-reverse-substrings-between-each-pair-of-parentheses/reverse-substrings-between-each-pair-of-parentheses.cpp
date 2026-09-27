class Solution {
public:
    string reverseParentheses(string s) {
        string ans="";
        int n=s.size();
        stack<char> st;
        for(char ch : s){
            if(ch==')'){
                string temp="";
                while(st.top()!='('){
                    temp+=st.top();
                    st.pop();
                }
                st.pop();
                for(char ele: temp){
                    st.push(ele);
                }
            }
            else st.push(ch);
        }
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        reverse(begin(ans),end(ans));
        return ans;
    }
};