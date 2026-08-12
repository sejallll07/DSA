class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int, int> mpp;

        int left = 0;
        int large = 0;

        for(int right = 0; right < nums.size(); right++) {

            mpp[nums[right]]++;

            while(mpp[nums[right]] > k) {
                mpp[nums[left]]--;
                left++;
            }

            large = max(large, right - left + 1);
        }

        return large;
    }
};