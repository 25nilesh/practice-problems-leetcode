class Solution {
public:
    vector<string> result;
    void solve(string& num,long long target,int idx,string exp,long long value,long long prev){
        if(idx==num.size()){
            if(value==target){
                result.push_back(exp);
            }
            return;
        }
        for(int j=idx;j<num.size();j++){
            string part=num.substr(idx,j-idx+1);
            long long curr=stoll(part);
            if(j>idx && num[idx]=='0') continue;
            if(idx==0){
                solve(num,target,j+1,part,curr,curr);
            }else{
                solve(num,target,j+1,exp+"+"+part,value+curr,curr);
                solve(num,target,j+1,exp+"-"+part,value-curr,-curr);
                solve(num,target,j+1,exp+"*"+part,value-prev+prev*curr,prev*curr);
            }
        }
    }
    vector<string> addOperators(string num, int target) {
        solve(num,target,0,"",0,0);
        return result;
    }
};