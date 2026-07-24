class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        unordered_set<int> s1;
        unordered_set<int> s2;
        int n=nums.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1.insert(nums[i]^nums[j]);
            }
        }
        for(auto XorPair:s1){
            for(int i=0;i<n;i++){
                s2.insert(XorPair^nums[i]);
            }
        }
        return s2.size();
    }
};