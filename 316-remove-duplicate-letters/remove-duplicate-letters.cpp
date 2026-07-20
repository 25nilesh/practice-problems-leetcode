class Solution {
public:
// nilesh
    string removeDuplicateLetters(string s) {
        vector<int> lastIdx(26,-1);
        vector<bool> visited(26,false);
        for(int i=0;i<s.size();i++){
            lastIdx[s[i]-'a']=i;
        }
        stack<char> st;
        for(int i=0;i<s.size();i++){
            char ch=s[i];
            if(visited[ch-'a']) continue;

            if(st.empty()) {
                st.push(ch);
                visited[ch-'a'] = true;
                continue;
            }
            int top_ele=st.top();
            if(top_ele<ch){
                st.push(ch);
                visited[ch-'a']=true;
            }
            else if(top_ele>ch){
                while(!st.empty() && st.top()>ch && lastIdx[st.top()-'a']>i){
                    visited[st.top()-'a']=false;
                    st.pop();
                }
                st.push(ch);
                visited[ch-'a']=true;
            }
        }
        string result="";
        while(!st.empty()){
            char ch=st.top();
            result+=ch;
            st.pop();
        }
        reverse(begin(result),end(result));
        return result;
    }
};