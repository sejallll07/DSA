class Solution {
public:
    int numOfSubarrays(vector<int>& nums, int k, int threshold) {
        int n = nums.size();
        int sum =0;
        int cnt = 0;
        for(int i=0;i<=n-k;i++){
            int j = 0;
            while(i==0 && j<k){
                sum += nums[j];
                j++;
            }

            if(i!=0){
                sum = sum - nums[i-1];
                sum = sum +  nums[i+(k-1)];
            }

            if((sum/k) >= threshold) cnt++;
        }

        return cnt;
    }
};