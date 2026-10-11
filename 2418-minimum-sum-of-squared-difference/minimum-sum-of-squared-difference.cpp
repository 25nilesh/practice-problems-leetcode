class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        vector<int> diff(100001,0);
        int n=nums1.size();
        int k=k1+k2;
        long long result=0;
        for(int i=0;i<n;i++){
            int difference=abs(nums1[i]-nums2[i]);
            diff[difference]++;
        }
        for(int i=100000;i>0 && k>0;i--){
            int ops=min(diff[i],k);
            diff[i]-=ops;
            diff[i-1]+=ops;
            k-=ops;
        }
        for(int i=0;i<=100000;i++){
            if(diff[i]!=0){
                result +=1LL*diff[i]*i*i;
            }
        }
        return result;
    }
};