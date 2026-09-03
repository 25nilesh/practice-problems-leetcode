class Solution {
public:
    bool uniformArray(vector<int>& nums) {
        bool even=false;
        bool odd=false;
        int minOdd=INT_MAX;
        for(int ele:nums){
            if(ele%2==0){
                even=true;
            }else{
                odd=true;
                minOdd=min(minOdd,ele);
            }
        }
        if(even==false || odd==false) return true;

        for(int ele:nums){
            if(ele%2==0 && ele<minOdd){
                return false;
            }
        }
        return true;
    }
};