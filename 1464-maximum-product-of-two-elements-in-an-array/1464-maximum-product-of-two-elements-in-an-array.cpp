class Solution {
public:
    int maxProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int cnt =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]<0)cnt++;
            else{
                break;
            }
        }
        int n = nums.size();
        if(cnt>1){
            return max((nums[cnt-1]-1)*(nums[cnt-2]-1) , (nums[n-1]-1)*(nums[n-2]-1));
        }else{
            return  (nums[n-1]-1)*(nums[n-2]-1);
        }


    }
};