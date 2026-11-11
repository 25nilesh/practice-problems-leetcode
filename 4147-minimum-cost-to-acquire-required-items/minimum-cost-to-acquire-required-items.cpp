class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long ans=0;
        int both=min(need1,need2);
        if(cost1+cost2<=costBoth){
            return 1LL * ((1LL * need1*cost1) + (1LL * need2*cost2));
        }else{
            while(need1>0 && need2>0){
                ans+=(1LL * costBoth * both);
                need1-=both;
                need2-=both;
            }
            if(need1>0){
                ans+= 1LL * need1*(min(cost1,costBoth));
            }
            if(need2>0){
                ans+= 1LL * need2*(min(cost2,costBoth));
            }
        }
        return ans;
    }
};