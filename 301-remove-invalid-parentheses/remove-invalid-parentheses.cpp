class Solution {
public:
    unordered_set<string> result;
    void removeParentheses(int idx,string& str,int count,const string& s,int& maxLen){
        if(count<0){
            return;
        }
        if(idx==s.size()){
            if(count==0){
                if(str.size()>maxLen){
                    maxLen=str.size();
                    result.clear();
                }
                if(str.size()==maxLen){
                    result.insert(str);
                }
            }
            return;
        }
        if(s[idx]!='(' && s[idx]!=')'){
            str.push_back(s[idx]);
            removeParentheses(idx+1,str,count,s,maxLen);
            str.pop_back();
            return;
        }
        str.push_back(s[idx]);
        removeParentheses(idx+1,str,count+(s[idx]=='(' ? 1 : -1),s,maxLen);
        str.pop_back();
        removeParentheses(idx+1,str,count,s,maxLen);
    }
    vector<string> removeInvalidParentheses(string s) {
        result.clear();
        int maxLen=0;
        string str=""; 
        removeParentheses(0,str,0,s,maxLen);
        vector<string> vec(result.begin(),result.end()); 
        return vec;
    }
};