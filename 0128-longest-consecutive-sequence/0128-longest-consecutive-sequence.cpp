class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n==0)return 0;
        int maxi = 1;
        int cnt = 1;
        for(int i=0;i<n-1;i++){
            if((nums[i+1]-nums[i])==1 || (nums[i+1]-nums[i])==0){
                if((nums[i+1]-nums[i])==1){
                    cnt++;
                }
                maxi = max(maxi , cnt);
            }else{
                
                
                cnt = 1;
            }
            

        }
        return maxi;
    }
};