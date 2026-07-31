class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26,0);
        int n=word.size();
        for(int i=0;i<n;i++){
            freq[word[i]-'a']++;
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int result=0;
        // n=freq.size();
        // for(int i=0;i<n;i++){
        //     int count=freq[i];
            // if(i<8){
            //     result+=count;
            // }else if(i>=8 && i<16){
            //     result+=2*count;
            // }else if(i>=16 && i<24){
            //     result+=3*count;
            // }else{
            //     result+=4*count;
            // }
            
        // }
        for (int i = 0; i < 26; i++) {
            result += freq[i] * (i / 8 + 1);
        }
        return result;
    }
};