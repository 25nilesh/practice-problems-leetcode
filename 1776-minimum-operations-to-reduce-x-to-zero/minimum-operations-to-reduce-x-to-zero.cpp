class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int ans=INT_MIN;
        int sum=0;
        mp[0]=-1;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            mp[sum]=i;
        }
        if(sum<x) return -1;
        int target=sum-x;
        sum=0;
        for(int i=0;i<n;i++){
            sum+=nums[i];
            int ele=sum-target;
            if(mp.find(ele)!=mp.end()){
                ans=max(ans,i-mp[ele]);
            }
        }
        return ans==INT_MIN?-1:n-ans;
    }
};