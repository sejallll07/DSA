
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int cnt = 0;
        vector<long long> pref;
        pref.push_back(0);

        long long sum = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {
            sum += nums[i];
            pref.push_back(sum);
        }

        long long prefsum = 0;

        for (int i = 0; i < n - 1; i++) {
            prefsum += nums[i];

            int l = i + 1;
            int r = n - 1;

            long long rearsum = pref[r + 1] - pref[l];

            if (prefsum >= rearsum) {
                cnt++;
            }
        }

        return cnt;
    }
};
