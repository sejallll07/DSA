class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int total_sum = std::accumulate(nums.begin(),nums.end(),0);
        int sumfirst = (target + total_sum)/2;

        if(abs(target) > total_sum)
            return 0;

        if((target + total_sum) % 2 != 0)
            return 0;

        int n = nums.size()+1;
        vector<vector<int>> t(n + 1, vector<int>(sumfirst + 1, 0));
        t[0][0] = 1;

        for(int i=1;i<n;i++){
            for(int j=0;j<sumfirst+1;j++){
                if(nums[i-1]<=j){
                    t[i][j] = t[i-1][j] + t[i-1][j-nums[i-1]];
                }else{
                    t[i][j] = t[i-1][j];
                }
            }
        }

        return t[n-1][sumfirst];
    }


};