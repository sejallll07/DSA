class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        long long maxi = 0;
        long long sum = 0;

        unordered_map<int,int> mp;
        for(int i = 0; i < k; i++){
            sum += nums[i];
            mp[nums[i]]++;
        }
        if(mp.size() == k){
            maxi = max(maxi, sum);
        }
        for(int i = 1; i <= n-k; i++){
            sum -= nums[i-1];
            mp[nums[i-1]]--;

            if(mp[nums[i-1]] == 0){
                mp.erase(nums[i-1]);
            }
            sum += nums[i+k-1];
            mp[nums[i+k-1]]++;
            if(mp.size() == k){
                maxi = max(maxi, sum);
            }
        }

        return maxi;
    }
};