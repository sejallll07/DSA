class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int stable_index = INT_MAX;
        int n = nums.size();
        for(int i=0;i<n;i++){
            int maxi =  *std::max_element(nums.begin() , nums.begin()+i);
            int mini = *std::min_element(nums.begin()+i , nums.end());

            int score = maxi - mini;
            if(score <= k){
                stable_index = min(stable_index , i);
            }
        }

        if(stable_index < n )return stable_index;

        return -1;

    }
};