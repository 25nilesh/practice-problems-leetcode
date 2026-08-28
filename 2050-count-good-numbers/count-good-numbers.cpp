class Solution {
public:
    int mod=1e9+7;
    #define ll long long int
    // long long solve(long long n,long long idx){
    //     // base case
    //     if(idx==n){
    //         return 1;
    //     }
    //     long long result;
    //     if(idx%2==0) result=5*solve(n,idx+1);
    //     if(idx%2!=0) result=4*solve(n,idx+1);
    //     return result % mod;
    // }

    ll binaryExponentationRec(ll a,ll b){
        if(b==0){
            return 1;
        }
        ll half=binaryExponentationRec(a,b/2);
        ll result=(half*half)%mod;
        if(b%2==1){
            result = (result * a)%mod;
        }
        return result%mod;
    }
    int countGoodNumbers(long long n) {
        // return solve(n,0);
        ll even = (n+1)/2;
        ll odd =n/2;
        return (binaryExponentationRec(5,even)*binaryExponentationRec(4,odd))%mod;
    }
};