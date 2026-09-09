class Solution {
public:
    int rob(vector<int>& nums) {
        int prev = nums[0];
        int prev2 = 0;
        int n = nums.size();
        if(n==1)return nums[0];
        for(int i=1;i<nums.size();i++){
            int take = nums[i];
            if(i>1) take += prev2;

            int non_take = 0 + prev;
            int curi = max(take , non_take);

            prev2 = prev ;
            prev = curi;

            
        }

        return prev;
    }
};