class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();

        vector<int> ans(n);

        int l = 0;
        int r = n - 1;
        int pos = n - 1;

        while (l <= r) {
            int left = nums[l] * nums[l];
            int right = nums[r] * nums[r];

            if (left > right) {
                ans[pos] = left;
                l++;
            } else {
                ans[pos] = right;
                r--;
            }

            pos--;
        }

        return ans;
    }
};