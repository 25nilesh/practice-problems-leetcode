class Solution {
public:
    void solve(vector<int>& nums,vector<int>& curr,vector<vector<int>>& result,int idx){
        if(idx==nums.size()){
            result.push_back(curr);
            return;
        }
        curr.push_back(nums[idx]);
        solve(nums,curr,result,idx+1);
        curr.pop_back();
        int j=idx+1;
        while(j<nums.size() && nums[j]==nums[j-1]) j++;
        solve(nums,curr,result,j);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> curr;
        sort(nums.begin(),nums.end());
        solve(nums,curr,result,0);
        return result;
    }
};