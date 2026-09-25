class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int number=0;
        for(int i=0;i<32;i++){
            int countZeros=0,countOnes=0;
            for(int& num:nums){
                if(num&(1<<i)){
                    countOnes++;
                }else{
                    countZeros++;
                }
            }
            if(countOnes%3==1){
                number=number|(1<<i);
            }
        }
        return number;
    }
};