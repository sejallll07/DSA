class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int , int>mpp;
        int sum =0;
        int maxi = 0;
        mpp[0] = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) sum--;
            if(nums[i]==1) sum++;

            if(mpp.find(sum)!=mpp.end()){
                maxi = max(i-mpp[sum] , maxi);
            
            }else{
                mpp[sum] = i;
            }
        }

        return maxi;
    }
};