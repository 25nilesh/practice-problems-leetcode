class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> prefixMax(n);
        prefixMax[0]=nums[0];
        vector<int> prefixMin(n);
        prefixMin[n-1]=nums[n-1];
        for(int i=1;i<n;i++){
            prefixMax[i]=max(prefixMax[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            prefixMin[i]=min(prefixMin[i+1],nums[i]);
        }
        int idx=-1;
        for(int i=0;i<n;i++){
            if(prefixMax[i]-prefixMin[i]<=k) {
                idx=i;
                break;
            }
        }
        return idx;
    }
};