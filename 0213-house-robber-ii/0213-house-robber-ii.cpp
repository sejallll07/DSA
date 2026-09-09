class Solution {
public:
    int solve(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;

        for(int i=1;i<nums.size();i++){
            int take = nums[i];
            if(i>1)take+=prev2;
            int  non_take = 0+prev;
            int  curi = max(take , non_take);
            prev2 = prev;
            prev = curi;
        }
        return prev;
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1)
            return nums[0];
        vector<int>temp1 , temp2;
        for(int i=0;i<nums.size();i++){
            int n = nums.size();
            if(i!=0)temp1.push_back(nums[i]);
            if(i!=n-1)temp2.push_back(nums[i]);
        }
        int ans = max(solve(temp1) , solve(temp2));
        return ans;

    }
};