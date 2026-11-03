class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int maxi=0;
        for(int i=0;i<n;i++){
            maxi=max(nums[i],maxi);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=abs(maxi-nums[i]);
        }
        return ans;
    }
};