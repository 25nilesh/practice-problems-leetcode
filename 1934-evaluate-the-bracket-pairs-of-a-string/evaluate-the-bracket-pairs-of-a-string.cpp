class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> mp;
        for(auto& pairs:knowledge){
            mp[pairs[0]]=pairs[1];
        }
        string res="";
        int n=s.size();
        int i=0;
        while(i<n){
            if(s[i]=='('){
                i++;
                string str="";
                while(s[i]!=')'){
                    str+=s[i];
                    i++;
                }
                if(mp.find(str)!=mp.end()){
                    res+=mp[str];
                }else{
                    res+='?';
                }
                i++;
            }else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};