class Solution {
public:
    bool checkDivisibility(int n) {
        int digitSum=0;
        int digitProd=1;
        int num=n;
        while(n>0){
            int digit=n%10;
            digitSum+=digit;
            digitProd*=digit;
            n/=10;
        }
        return num%(digitSum+digitProd)==0;
    }
};