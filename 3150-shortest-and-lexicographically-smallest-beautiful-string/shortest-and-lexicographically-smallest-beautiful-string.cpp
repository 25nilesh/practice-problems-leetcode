class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // brute force 
        int n=s.size();
        for(int len=k;len<=n;len++){
            string res="";
            for(int j=0;j<=n-len;j++){
                string temp=s.substr(j,len);
                int countOnes=0;
                for(char& ch:temp){
                    countOnes+=(ch=='1')?1:0;
                }
                if(countOnes==k){
                    if(res.empty() || temp<res){
                        res=temp;
                    }
                }
            }
            if(!res.empty()) return res;
        }
        return "";
    }
};