class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        sort(begin(nums),end(nums));
        int inc=k;
        for(int ele:nums){
            if(ele<inc) continue;
            else if(ele==inc){
                inc+=k;
            }
            else if(ele>inc){
                break;
            }
        }
        return inc;
    }
};