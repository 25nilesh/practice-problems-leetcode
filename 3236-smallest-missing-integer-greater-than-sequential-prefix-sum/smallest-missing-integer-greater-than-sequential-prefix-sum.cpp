class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int PrefixSum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1){
                PrefixSum+=nums[i];
            }
            else break;
        }
        sort(begin(nums),end(nums));
        for(int i=0;i<n;i++){
            if(nums[i]==PrefixSum){
                PrefixSum++;
            }else if(nums[i]>PrefixSum) {
                break;
            }
        }
        return PrefixSum;
    }
};