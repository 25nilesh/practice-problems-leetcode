class Solution {
public:
    bool isPalindrome(string s){
        int n=s.size();
        int i=0;
        int j=n-1;
        while(i<j){
            if(s[i]!=s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    void solve(int i,string& s, vector<string>& curr,vector<vector<string>>& result ){
        if(i==s.size()){
            result.push_back(curr);
            return;
        }

        for(int idx=i;idx<s.size();idx++){
            string str=s.substr(i,idx-i+1);
            if(isPalindrome(str)) {
                curr.push_back(str);
                solve(idx+1,s,curr,result);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> result;
        vector<string> curr;
        solve(0,s,curr,result);
        return result;
    }
};