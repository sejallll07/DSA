class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());

        int i=0;
        int n = nums.size();
        vector<int> ans;
        while(nums[i]<=target){
            if(nums[i]==target)ans.push_back(i);
            if(i<n-1) i++;
            else{
                break;
            }
        }

        return ans;
    }
};