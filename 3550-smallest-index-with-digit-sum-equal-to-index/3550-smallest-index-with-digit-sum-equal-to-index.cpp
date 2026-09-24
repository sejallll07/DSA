class Solution {
public:
    int smallestIndex(vector<int>& nums) {
        int mini = nums.size();
        for(int i=0;i<nums.size();i++){
            int k = nums[i];
            int sum = 0;
            while(k>0){
                int rem = k%10;
                k = k/10;


                sum += rem;
            }
            if(sum==i){
                mini = min(mini , i);
            }
        }

        if(mini<nums.size())return mini;

        return -1;
    }
};