class Solution {
public:
    int reverseDegree(string s) {
        int n=s.size();
        vector<int> arr(26);
        int cnt=26;
        int result=0;
        for(int i=0;i<26;i++){
            arr[i]=cnt--;
        }
        for(int i=0;i<n;i++){
            result+=arr[s[i]-'a']*(i+1);
        }
        return result;
    }
};