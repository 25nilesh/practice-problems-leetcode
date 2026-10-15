class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int n=nums.size();
        int result=0;
        // for(int i=0;i<n;i++){
        //     for(int j=i;j<n;j++){
        //         unordered_set<int> st;
        //         for(int k=i;k<=j;k++){
        //             st.insert(nums[k]);
        //         }
        //         result+=(st.size() * st.size());
        //     }
        // }
        for (int i = 0; i < n; i++) {
            unordered_set<int> st;
            for (int j = i; j < n; j++) {
                st.insert(nums[j]);
                // Add st.size() * st.size() to result
                result+=(st.size() * st.size());
            }
}
        return result;
    }
};