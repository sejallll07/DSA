class Solution {
public:
    bool canJump(vector<int>& nums) {

        int max_ind = 0;
        
        int n =  nums.size();
        int dest;
        for(int i=0;i<nums.size();i++){
            if(max_ind >=i ){
                dest = i+nums[i];
                max_ind = max(max_ind , dest);
            }
            
            
        }

        return max_ind >= n-1;
    }
};