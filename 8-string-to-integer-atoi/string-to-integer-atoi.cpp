class Solution {
public:
    int n;
    // const int INT_MIN_VAL=INT_MIN;
    // const int INT_MAX_VAL=INT_MAX;
    int helper(string str, int i,long long result,int sign){
        if(i>=n || !isdigit(str[i])){
            return (int) (sign*result);
        }

        result=result*10+str[i]-'0';

        if(sign * result >=INT_MAX) return INT_MAX;
        if(sign * result <=INT_MIN) return INT_MIN;

        return helper(str,i+1,result,sign);
    }
    int myAtoi(string s) {
        int i=0;
        n=s.size();
        while(i<n && s[i]==' '){
            i++;
        }
        if(i==n) return 0;
        int sign=1;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            sign=(s[i]=='-')?-1:1;
            i++;
        }
        long long result=0;
        return helper(s,i,result,sign);
    }
};