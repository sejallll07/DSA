class Solution {
public:
    int minOperations(vector<int>& nums) {
        vector<int> dranofelik = nums;

        int n = nums.size();
        int ans = INT_MAX;

        
        bool inc = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] != (nums[i - 1] + 1) % n) {
                inc = false;
                break;
            }
        }

        if (inc) {
            int pos0 = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == 0) {
                    pos0 = i;
                    break;
                }
            }

            
            ans = min(ans, pos0);

            
            ans = min(ans, n - pos0 + 2);
        }

        
        bool dec = true;
        for (int i = 1; i < n; i++) {
            if (nums[i] != (nums[i - 1] - 1 + n) % n) {
                dec = false;
                break;
            }
        }

        if (dec) {
            int posMax = 0;
            for (int i = 0; i < n; i++) {
                if (nums[i] == n - 1) {
                    posMax = i;
                    break;
                }
            }

            
            ans = min(ans, posMax + 1);

            
            ans = min(ans, n - posMax + 1);
        }

        if (ans == INT_MAX) return -1;
        return ans;
    }
};