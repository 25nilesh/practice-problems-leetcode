class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ones=0;
        int sumZeros=0;
        int currZeros=-1;
        int i=0;
        
        while(i<n){
            if(s[i]=='1'){
                ones++;
                i++;
            }else{
                int curr=0;
                while(i<n && s[i]=='0'){
                    curr++;
                    i++;    
                }
                if(currZeros>0){
                    sumZeros=max(sumZeros,currZeros+curr);
                }
                currZeros=curr;
            }
        }
        return sumZeros+ones;
    }
};