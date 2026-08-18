class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> freq(51,0);
        int n=nums.size();
        int ans=-1;
        for(int i=0;i<=n-k;i++){
            unordered_set<int> s;
            for(int j=i;j<i+k;j++){
                s.insert(nums[j]);
            }
            for(int ele:s){
                freq[ele]++;
            }
        }
        for(int i=0;i<51;i++){
            if(freq[i]==1){
                ans=max(ans,i);
            }
        }
        return ans;
    }
};