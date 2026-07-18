class Solution {
public:
    int findGCD(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        return solve(nums[0], nums[n-1]);

    }

    int solve(int a , int b){
        while(b){
            int temp = a % b;
            a = b ;
            b = temp;
        }

        return a;
    }
};