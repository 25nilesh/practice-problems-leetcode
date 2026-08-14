class Solution {
public:
    int maximumLengthSubstring(string s) {
        int n=s.size();
        unordered_map<char,int> mp;
        int i=0;
        int j=0;
        int ans=0;
        while(j<n){
            mp[s[j]]++;
            if(mp[s[j]]>2){
                while(i<j && mp[s[j]]>2){
                    mp[s[i]]--;
                    i++;
                }
            }else{
                ans=max(ans,j-i+1);
            }
            j++;
        }
        return ans;
    }
};