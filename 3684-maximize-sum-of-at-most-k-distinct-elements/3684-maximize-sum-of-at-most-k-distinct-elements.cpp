class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int prev = nums[n-1];
        vector<int> ans;
        ans.push_back(nums[n-1]);
        k -= 1;
        if(n==1)return {nums[0]};
        // if(n==2 && nums[0]!=nums[1]){
        //     if(k>=2){
        //         return {max(nums[0],nums[1]),min(nums[0],nums[1])};
        //     }else{
        //         return {max(nums[0],nums[1])};
        //     }
            
        // }else{
        //     if(n==2){
        //         return {nums[0]};
        //     }
        // }
        for(int i=n-2;i>=0;i--){
            if(k!= 0 && nums[i]!=prev){
                ans.push_back(nums[i]);
                prev = nums[i];
                k--;
            }
        }

        return ans;
    }
};