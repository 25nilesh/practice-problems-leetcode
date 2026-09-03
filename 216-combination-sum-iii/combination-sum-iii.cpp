class Solution {
public:
    void solve(int idx,vector<int>& curr,vector<int>& nums,vector<vector<int>>& result,int k,int n){
        if(idx==nums.size()){
            if(n==0 && curr.size()==k){
                result.push_back(curr);
            }
            return;
        }
        if(n==0 && curr.size()==k){
            result.push_back(curr);
            return;
        }
        if(nums[idx]<=n){
            curr.push_back(nums[idx]);
            solve(idx+1,curr,nums,result,k,n-nums[idx]);
            curr.pop_back();
        }
        solve(idx+1,curr,nums,result,k,n);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> nums={1,2,3,4,5,6,7,8,9};
        vector<vector<int>> result;
        vector<int> curr;
        solve(0,curr,nums,result,k,n);
        return result;
    }
};