class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size();
        int neg_ind = -1;
        int pos_ind = -1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0) neg_ind = i;

            if(nums[i]>0){
                pos_ind = i;
                break;
            }
        }

        if(pos_ind != -1) pos_ind = n-pos_ind;
        return max(neg_ind+1 , pos_ind);
        
        
    }
};