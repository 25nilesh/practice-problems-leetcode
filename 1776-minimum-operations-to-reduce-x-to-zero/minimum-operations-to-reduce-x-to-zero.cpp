class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int> mp;
        mp[0]=-1;
        mp[nums[0]]=0;
        for(int i=1;i<n;i++){
            nums[i]+=nums[i-1];
            mp[nums[i]]=i;
        }
        if(nums[n-1]<x) return -1;
        int target=nums[n-1]-x;
        int ans=INT_MIN;
        for(int i=0;i<n;i++){
            int remaining=nums[i]-target;
            if(mp.find(remaining)!=mp.end()){
                ans=max(ans,i-mp[remaining]);
            }
        }
        return ans==INT_MIN?-1:n-ans;
    }
};