class Solution {
public:
    bool sorted(vector<int>& nums){
        for(int i = 1; i < nums.size(); i++){
            if(nums[i] < nums[i-1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {

        int ans = 0;

        while(!sorted(nums)){

            int sum = INT_MAX;
            int ind = 0;

            for(int i = 0; i < nums.size()-1; i++){

                if(nums[i] + nums[i+1] < sum){
                    sum = nums[i] + nums[i+1];
                    ind = i;
                }
            }

            nums[ind] = sum;
            nums.erase(nums.begin() + ind + 1);

            ans++;
        }

        return ans;
    }
};