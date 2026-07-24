class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        // unordered_set<int> s1;
        // unordered_set<int> s2;
        // int n=nums.size();
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         s1.insert(nums[i]^nums[j]);
        //     }
        // }
        // for(auto XorPair:s1){
        //     for(int i=0;i<n;i++){
        //         s2.insert(XorPair^nums[i]);
        //     }
        // }
        // return s2.size();

        int n=nums.size();
        int maxEle=*max_element(nums.begin(),nums.end());

        int T=1;
        while(T<=maxEle){
            T<<=1;
        }
        vector<bool> s1(T,false);
        vector<bool> s2(T,false);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i]^nums[j]]=true;
            }
        }
        for(int i=0;i<T;i++){
            if(s1[i]){
                for(int& num:nums){
                    s2[i^num]=true;
                }
            }
        }
        int cnt=0;
        for(int i=0;i<T;i++){
            if(s2[i]) cnt++;
        }
        return cnt;
    }
};