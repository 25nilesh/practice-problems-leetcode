class Solution {
public:
    bool sumGame(string num) {
        int leftSum=0;
        int rightSum=0;
        int leftQ=0;
        int rightQ=0;
        int n=num.size();
        for(int i=0;i<n;i++){
            if(i<n/2 && num[i]!='?') leftSum+=num[i]-'0';
            else if(i<n/2 && num[i]=='?') leftQ++;
            else if(i>=n/2 && num[i]=='?') rightQ++;
            else if(i>=n/2 && num[i]!='?') rightSum+=num[i]-'0';
        }
        if((leftQ+rightQ)%2!=0) return true;

        int leftValue= leftSum+4.5*(leftQ);     
        int rightValue= rightSum+4.5*(rightQ);     

        return leftValue!=rightValue;
    }
};