class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int first = nums[0];
        int last = nums[n-1];
        int i =0;
        vector<int>ans;
        while(first<=last && i<n){
            if(first != nums[i]){
                ans.push_back(first);
                first++;

            }else{
                i++;
                first++;
            }
        }

        return ans;
        
    }
};