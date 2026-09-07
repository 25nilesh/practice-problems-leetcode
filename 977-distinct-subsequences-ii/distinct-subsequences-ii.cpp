class Solution {
public:
    int mod=1e9+7;
    int distinctSubseqII(string s) {
        vector<int> end(26,0);
        int total_subseq=0;
        for(char ch: s){
            int index=ch-'a';
            int new_subseq=(total_subseq+1-end[index]+mod)%mod;
            total_subseq=(total_subseq+new_subseq)%mod;
            end[index]=(end[index]+new_subseq)%mod;
        }  
        return total_subseq; 
    }
};