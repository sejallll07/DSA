class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = nums[0];
        int mini = nums[0];
        int prod = nums[0];
        for(int i=1;i<nums.size();i++){
            if(nums[i]<0){
                swap(mini , maxi);

            }

            maxi = max(nums[i] , maxi*nums[i]);
            mini = min(nums[i] , mini*nums[i]);

            prod = max(prod , maxi);
        }

        return prod;
    }
};