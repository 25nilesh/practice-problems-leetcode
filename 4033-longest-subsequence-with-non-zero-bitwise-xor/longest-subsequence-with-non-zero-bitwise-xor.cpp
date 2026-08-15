class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n=nums.size();
        int allXor=0;
        bool allZeros=true;
        for(int i=0;i<n;i++){
            if(nums[i]!=0) allZeros=false;
            allXor^=nums[i]; 
        }
        if(allXor==0 && allZeros) return 0;
        if(allXor==0) return n-1;
        return n;
    }
};