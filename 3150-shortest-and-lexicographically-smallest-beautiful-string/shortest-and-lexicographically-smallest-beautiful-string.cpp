class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        // brute force  t.c = O(n^3)
        // int n=s.size();
        // for(int len=k;len<=n;len++){
        //     string res="";
        //     for(int j=0;j<=n-len;j++){
        //         string temp=s.substr(j,len);
        //         int countOnes=0;
        //         for(char& ch:temp){
        //             countOnes+=(ch=='1')?1:0;
        //         }
        //         if(countOnes==k){
        //             if(res.empty() || temp<res){
        //                 res=temp;
        //             }
        //         }
        //     }
        //     if(!res.empty()) return res;
        // }
        // return "";

        // optimal using sliding window 
        int n=s.size();
        int i=0;
        int j=0;
        int cntOnes=0;
        string result="";
        while(j<n){
            if(s[j]=='1'){
                cntOnes++;
            }
            while(cntOnes>k || s[i]=='0'){
                if(s[i]=='1'){
                    cntOnes--;
                }
                i++;
            }
            if(cntOnes==k){
                int len=j-i+1;
                string temp=s.substr(i,len);
                if(result.empty() || result.size()>temp.size() || (result.size()==temp.size() && temp<result) ){
                    result=temp;
                }
            }
            j++;
        }
        return result;

    }
};