class Solution {
public:
    void solve(int idx,string& str,unordered_map<char,string>& mp,string digits,vector<string>& result){
        if(idx==digits.size()){
            result.push_back(str);
            return;
        }
        char ch=digits[idx];
        string s=mp[ch];
        for(int i=0;i<s.size();i++){
            str.push_back(s[i]);
            solve(idx+1,str,mp,digits,result);
            str.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> mp;
        vector<string> result;
        string str="";
        for(char& ch: digits){
            if(ch=='2') mp['2']="abc";
            else if(ch=='3') mp['3']="def";
            else if(ch=='4') mp['4']="ghi";
            else if(ch=='5') mp['5']="jkl";
            else if(ch=='6') mp['6']="mno";
            else if(ch=='7') mp['7']="pqrs";
            else if(ch=='8') mp['8']="tuv";
            else  mp['9']="wxyz";
        }
        solve(0,str,mp,digits,result);
        return result;
    }
};