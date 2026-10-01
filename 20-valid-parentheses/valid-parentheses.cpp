class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        for(char ch: s){
            if(ch=='(' || ch=='{' || ch=='['){
                st.push(ch);
            }else if((ch==')' || ch=='}' || ch==']') && st.empty()){
                return false;
            }else if(ch==')' && st.top()=='('){
                st.pop();
            }else if(ch=='}' && st.top()=='{'){
                st.pop();
            }else if(ch==']' && st.top()=='['){
                st.pop();
            }else{
                return false;
            }
        }
        return st.empty();
    }
};