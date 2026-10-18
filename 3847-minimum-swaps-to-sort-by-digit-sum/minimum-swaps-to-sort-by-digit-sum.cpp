class Solution {
public:
    static int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }

    static bool cmp(int a, int b) {
        int x = digitSum(a);
        int y = digitSum(b);

        if (x != y) return x < y;
        return a < b;
    }

    int minSwaps(vector<int>& nums) {
        vector<int> num = nums;
        sort(num.begin(), num.end(), cmp);

        unordered_map<int, int> mp;
        for (int i = 0; i < nums.size(); i++) {
            mp[nums[i]] = i;
        }

        int swaps = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == num[i]) continue;

            int pos = mp[num[i]];

            mp[nums[i]] = pos;
            mp[num[i]] = i;

            swap(nums[i], nums[pos]);
            swaps++;
        }

        return swaps;
    }
};