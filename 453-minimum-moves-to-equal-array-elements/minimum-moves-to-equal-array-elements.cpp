class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n=nums.size();
        int min_element=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]<min_element){
                min_element=nums[i];
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(nums[i]-min_element);
        }
        return ans;
    }
};