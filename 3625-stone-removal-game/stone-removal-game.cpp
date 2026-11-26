class Solution {
public:
    bool solve(int n,int turn,int prev){
        if (n < prev) {
            return turn == 0;
        }

        return solve(n - prev, 1 - turn, prev - 1);
    }
    bool canAliceWin(int n) {
        if(n<10) return false;
        return solve(n,1,10);
    }
};