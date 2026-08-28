class Solution {
public:
    string result="";
    char mid;
    bool solve(string curr,string target,vector<int>& freq,int i,bool greater){
        if(i==target.size()/2){
            string p=curr;
            reverse(curr.begin(),curr.end());
            if(target.size()%2==1){
                p=p+mid;
            }
            p=p+curr;
            if(p>target){
                result=p;
                return true;
            }
            return false;
        }
        for(char ch='a';ch<='z';ch++){
            if(freq[ch-'a']==0) continue;
            if(greater==false && ch<target[i]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;

            bool isGreater= greater || ch>target[i];

            if(solve(curr,target,freq,i+1,isGreater)){
                return true;
            }
            curr.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }
    string lexPalindromicPermutation(string s, string target) {
        string curr="";
        vector<int> freq(26,0);
        for(char& ch: s){
            freq[ch-'a']++;
        }
        int oddCnt=0;
        for(int i=0;i<26;i++){
            if(freq[i]%2==1){
                mid=i+'a';
                oddCnt++;
            }
            if(oddCnt>1) {
                return "";
            }
            freq[i]/=2;
        }
        solve(curr,target,freq,0,false);
        return result;
    }
};