class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        int largest=nums[0];
        int mini=*min_element(nums.begin(),nums.end());
        // vector<int> suffixMin(n);
        // suffixMin[n-1]=nums[n-1];
        // for(int i=n-2;i>=0;i--){
        //     suffixMin[i]=min(suffixMin[i+1],nums[i]);
        // }
        int idx=-1;
        for(int i=0;i<n;i++){
            largest=max(largest,nums[i]);
            if(largest-mini<=k) {
                idx=i;
                break;
            }
            if(nums[i]==mini && i+1<n) {
                mini=*min_element(nums.begin()+i+1,nums.end());
            }
        }
        return idx;
    }
};