class Solution {
public:
    double findMaxAverage(vector<int>& nums, double k) {
        int n = nums.size();
        double maxi = INT_MIN;
        double sum =0;
        for(int i=0;i<=n-k;i++){
            int j =0;
            while(j<k && i==0){
                sum = sum + nums[j];
                j++;
            }
            if( i != 0){
                sum = sum - nums[i-1] ;
                sum = sum + nums[i+(k-1)] ;
            }
            maxi = max(maxi , sum/k);

        }

        return maxi;
        
    }
};