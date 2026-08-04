class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int small=INT_MAX;
        int large=INT_MIN;
        int n=nums.size();
        vector<bool> visited(100,0);
        for(int i=0;i<n;i++){
            visited[nums[i]]=true;
            if(nums[i]>large) large=nums[i];
            if(nums[i]<small) small=nums[i];
        }
        vector<int> result;
        for(int i=small;i<large;i++){
            if(!visited[i]) result.push_back(i);
        }
        return result;
    }
};