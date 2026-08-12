class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            mp[nums[j]]++;
            if(mp[nums[j]]<=k){
                ans=max(ans,j-i+1);
            }else{
                while(i<j && mp[nums[j]]>k){
                    mp[nums[i]]--;
                    i++;
                }
            }
            j++;
        }
        return ans;
    }
};