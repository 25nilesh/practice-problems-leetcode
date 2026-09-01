class Solution {
public:
    vector<vector<int>> result;
    void solve(int i,vector<int>& nums,int target,vector<int> curr){
        if(i==nums.size()){
            if(target==0){
                result.push_back(curr);
            }
            curr={};
            return;
        }
        if(target<0) {
            curr={};
            return;
        }
        curr.push_back(nums[i]);
        solve(i,nums,target-nums[i],curr);
        curr.pop_back();
        solve(i+1,nums,target,curr);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n=candidates.size();
        vector<int> curr;
        solve(0,candidates,target,curr);
        return result;
    }
};