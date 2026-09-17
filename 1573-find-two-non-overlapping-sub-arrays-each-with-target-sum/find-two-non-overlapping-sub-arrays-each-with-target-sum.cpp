class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n=arr.size();
        int i=0,j=0;
        int currSum=0;
        int bestMin=INT_MAX;
        int result=INT_MAX;
        vector<int> minLenTillIdx(n,INT_MAX);
        while(j<n){
            currSum+=arr[j];
            while(i<j && currSum>target){
                currSum-=arr[i];
                i++;
            }
            if(currSum==target){
                int len=j-i+1;
                if(i>0 && minLenTillIdx[i-1]!=INT_MAX){
                    result=min(result,len+minLenTillIdx[i-1]);
                }
                bestMin=min(bestMin,len);
            }
            minLenTillIdx[j]=bestMin;
            j++;
        }
        return result==INT_MAX ? -1 : result;
    }
};