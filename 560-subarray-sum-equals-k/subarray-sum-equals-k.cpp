class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int prefix=0;
        int count=0;
        for(int num:nums){
            prefix+=num;
            int remaining=prefix-k;
            if(mp.find(remaining)!=mp.end()){
                count+=mp[remaining];
            }
            mp[prefix]++;
        }
        return count;
    }
};