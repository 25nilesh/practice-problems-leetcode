class Solution {
public:
    #define ll long long
    vector<string> result;
    void solve(string& num,int target,int idx,string exp,ll value,ll prev){
        if(idx==num.size()){
            if(value==target){
                result.push_back(exp);
            }
            return;
        }
        for(int j=idx;j<num.size();j++){
            if(j>idx && num[idx]=='0') continue;
            string part=num.substr(idx,j-idx+1);
            ll curr=stoll(part);
            if(idx==0){
                solve(num,target,j+1,part,curr,curr);
            }else{
                solve(num,target,j+1,exp+"+"+part,value+curr,curr);
                solve(num,target,j+1,exp+"-"+part,value-curr,-curr);
                solve(num,target,j+1,exp+"*"+part,(value-prev)+(prev*curr),prev*curr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        string str="";
        solve(num,target,0,str,0,0);
        return result;
    }
};