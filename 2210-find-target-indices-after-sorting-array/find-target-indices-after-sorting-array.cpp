class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        vector<int> result;
        sort(nums.begin(),nums.end());
        int lo=0;
        int hi=nums.size()-1;
        int lower=-1;
        while(lo<=hi){
            int mid=lo+(hi-lo)/2;
            if(nums[mid]==target){
                lower=mid;
                hi=mid-1;
            }else if(nums[mid]>target){
                hi=mid-1;
            }else{
                lo=mid+1;
            }
        }
        if(lower==-1) return result;
        while(lower<nums.size() && nums[lower]==target){
            result.push_back(lower);
            lower++;
        }
        return result;
    }
};