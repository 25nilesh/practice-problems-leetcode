class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==INT_MAX || n==INT_MIN) return false;
        return n && !(n & (n-1));
    }
};