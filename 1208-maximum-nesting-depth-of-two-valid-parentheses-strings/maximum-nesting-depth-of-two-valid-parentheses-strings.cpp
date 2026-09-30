class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n=seq.length();
        vector<int> result(n);
        int cnt=0;
        for(int i=0;i<n;i++){
            if(seq[i]=='('){
                cnt++;
                result[i]=cnt%2;
            }else{
                result[i]=cnt%2;
                cnt--;
            }
        }
        return result;
    }
};