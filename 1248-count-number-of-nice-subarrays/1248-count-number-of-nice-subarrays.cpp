class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {

        int l = 0;
        int odd = 0;
        int cnt = 0;
        int even = 0;

        for (int r = 0; r < nums.size(); r++) {
            if (nums[r] % 2 != 0)
                odd++;
            if (odd > k) {
                if(nums[l] % 2 == 0)
                    l++;

                l++;
                odd--;

                even = 0;
            }
            if (odd == k) {
                while (nums[l] % 2 == 0) {
                    even++;
                    l++;
                }
                cnt += even + 1;
            }
        }

        return cnt;
    }
};