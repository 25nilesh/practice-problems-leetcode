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
        // if(n<0) return binaryExponentationRec(x,n);
        return binaryExponentationRec(x,n);
    }
};