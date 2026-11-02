class Solution {
public:
    int totalFruit(vector<int>& nums) {
        int l =0;
        int r = 0;
        int n = nums.size();
        int size = 2;
        int trees = 0;
        map<int , int>mpp;
        while(r<n){
            mpp[nums[r]]++;
            while(mpp.size()>2){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }

            if(mpp.size() <= 2){
                trees = max(trees , r-l+1);
            }

            r++;
        }

        return trees;
    }
};