class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return 1;
        int minIdx=0;
        int maxIdx=0;
        for(int i=1;i<n;i++){
            if(nums[i]<nums[minIdx]){
                minIdx=i;
            }
            if(nums[i]>nums[maxIdx]){
                maxIdx=i;
            }
        }
        int left=min(minIdx,maxIdx);
        int right=max(minIdx,maxIdx);

        int ans1=right+1;
        int ans2=n-left;
        int ans3=left+1+n-right;

        return min({ans1,ans2,ans3});

    }
};