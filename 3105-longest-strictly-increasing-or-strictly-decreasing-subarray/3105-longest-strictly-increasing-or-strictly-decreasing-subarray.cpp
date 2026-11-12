class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int inc = 0;
        int dec = 0;
        int max_inc = 0;
        int max_dec = 0;

        for(int i=0 ;i<nums.size()-1;i++){
            if(nums[i]<nums[i+1]){
                inc++;
                max_dec = max(dec , max_dec);
                dec =0;
            }else if(nums[i]==nums[i+1]){
                
                max_inc = max(max_inc , inc);
                max_dec = max(max_dec , dec);
                inc = 0;
                dec = 0;
            }else{
                dec++;
                max_inc = max(inc , max_inc);
                inc = 0;
            }

            max_inc = max(inc , max_inc);
            max_dec = max(dec , max_dec);
        }


        return max(max_inc , max_dec)+1;
    }
};