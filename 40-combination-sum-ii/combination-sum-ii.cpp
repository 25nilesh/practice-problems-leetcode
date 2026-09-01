class Solution {
public:
    vector<vector<int>> result;
    void solve(int i,vector<int>& candidates,int target,vector<int>& curr){
        if(i==candidates.size()){
            if(target==0){
                result.push_back(curr);
            }
            return;
        }
        if(target==0){
            result.push_back(curr);
            return;
        }
        if(target<0) return;
        if(candidates[i]<=target){
            curr.push_back(candidates[i]);
            solve(i+1,candidates,target-candidates[i],curr);
            curr.pop_back();
        }
        int j=i+1;
        while(j<candidates.size() && candidates[j]==candidates[j-1]) j++;
        solve(j,candidates,target,curr);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(begin(candidates),end(candidates));
        solve(0,candidates,target,curr);
        return result;
    }
};