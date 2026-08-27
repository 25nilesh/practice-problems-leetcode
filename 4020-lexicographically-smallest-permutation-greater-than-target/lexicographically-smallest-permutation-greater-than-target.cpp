class Solution {
public:
    string result="";
    bool solve(string curr,vector<int>& freq, string target,int i,bool greater){
        if(i==target.size()){
            if(greater){
                result=curr;
                return true;
            }
            return false;
        }

        for(char ch='a';ch<='z';ch++){
            if(freq[ch-'a']==0) continue;
            if(greater==false && ch<target[i]) continue;

            curr.push_back(ch);
            freq[ch-'a']--;

            bool isGreater=greater || ch>target[i];

            if(solve(curr,freq,target,i+1,isGreater)){
                return true;
            }
            curr.pop_back();
            freq[ch-'a']++;
        }
        return false;
    }

    string lexGreaterPermutation(string s, string target) {
        string curr="";
        vector<int> freq(26,0);
        for(char& ch: s){
            freq[ch-'a']++;
        }
        solve(curr,freq,target,0,false);
        return result;
    }
};