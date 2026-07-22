class Solution {
    priority_queue<int , vector<int> , greater<int>>pq;
public:
    vector<int> sortArray(vector<int>& nums) {
        vector<int> ans;
        int k = nums.size();
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        
        for(int i=0;i<k;i++){
            int s = pq.top();
            pq.pop();
            nums[i]=s;
        }

        return nums;
    }
};