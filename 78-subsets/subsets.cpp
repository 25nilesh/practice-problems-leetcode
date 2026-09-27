class Solution {
public:
    // void solve(int i,vector<int>& nums,vector<vector<int>>& ans,vector<int>& temp){
    //     if(i==nums.size()){
    //         ans.push_back(temp);
    //         return;
    //     }
    //     temp.push_back(nums[i]);
    //     solve(i+1,nums,ans,temp);
    //     temp.pop_back();
    //     solve(i+1,nums,ans,temp);
    // }
    vector<vector<int>> subsets(vector<int>& nums) {
        // vector<vector<int>> ans;
        // vector<int> temp;
        // solve(0,nums,ans,temp);
        // return ans;
        int n=nums.size();
        vector<vector<int>> ans;
        for(int i=0;i<(1<<n);i++){
            vector<int> temp={};
            for(int j=0;j<n;j++){
                if(i&(1<<j)){
                    temp.push_back(nums[j]);
                }
            }
            ans.push_back(temp);
        }
        return ans;
    }
};