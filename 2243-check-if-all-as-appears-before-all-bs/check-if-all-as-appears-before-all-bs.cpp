class Solution {
public:
    bool checkString(string s) {
        bool flag=false;
        for(char ch : s){
            if(ch=='a' && flag==false) continue;
            else if(ch=='a' && flag==true) return false;
            else if(ch=='b'){
                flag=true;
            }
        }
        return true;
    }
};