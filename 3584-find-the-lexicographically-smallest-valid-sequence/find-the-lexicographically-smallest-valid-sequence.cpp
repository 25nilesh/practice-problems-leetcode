class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n1=word1.size();
        int n2=word2.size();
        vector<int> suffix(n1+1,0);
        int i=n1-1;
        int j=n2-1;
        while (i >= 0) {
            if (j >= 0 && word1[i] == word2[j]) {
                suffix[i] = suffix[i + 1] + 1;
                j--;
            }
            else {
                suffix[i] = suffix[i + 1];
            }
            i--;
        }
        i=0;
        j=0;
        int oprns=1;
        vector<int> result;
        while(i<n1 && j<n2){
            if(word1[i]==word2[j]){
                result.push_back(i);
                i++;
                j++;
            }else{
                if(oprns==1){
                    if(suffix[i+1]>=n2-j-1){
                        result.push_back(i);
                        i++;
                        j++;
                        oprns=0;
                    }else{
                        i++;
                    }
                }else{
                    i++;
                }
            }
        }
        if(result.size()!=n2) return {}; 
        return result;
    }
};