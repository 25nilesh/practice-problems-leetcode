class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int largest=nums[0];
        vector<int> suffixMin(n);
        suffixMin[n-1]=nums[n-1];
        for(int i=n-2;i>=0;i--){
            suffixMin[i]=min(suffixMin[i+1],nums[i]);
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            largest=max(largest,nums[i]);
            int mini=suffixMin[i];
            if(largest-mini<=k) {
                idx=i;
                break;
            }
        }
        return idx;
    }
};