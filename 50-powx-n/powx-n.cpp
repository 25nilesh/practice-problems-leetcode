class Solution {
public:
    double binaryExponentationRec(double x,int n){
        if(n==-1) return 1/x;
        if(n==0) return 1;
        
        double half=binaryExponentationRec(x,n/2);
        double res=half*half;
        if(n%2==1){
            res=res*x;
        }
        else if(n%2==-1){ 
            res=res*(1/x);
        }
        return res;
    }
    double myPow(double x, int n) {
        // return binaryExponentationRec(x,n);

        // binary exponentation iterative 
        long long N=n;
        if(N<0){
            x=1/x;
            N=-N;
        }
        double ans=1;
        while(N>0){
            if(N%2==1){
                ans=ans*x;
            }
            x=x*x;
            N/=2;
        }
        return ans;
    }
};