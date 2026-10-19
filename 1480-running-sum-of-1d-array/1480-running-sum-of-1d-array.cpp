class Solution {
public:
    vector<int> runningSum(vector<int>& nums) {
        int total = 0;
        vector<int>sumarr;
        for(int i=0;i<nums.size();i++){
            total += nums[i];
            sumarr.push_back(total);
        }

        return sumarr;
    }
};