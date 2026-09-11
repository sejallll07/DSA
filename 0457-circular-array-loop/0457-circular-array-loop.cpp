class Solution {
public:
    bool circularArrayLoop(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0; i < n; i++) {
            bool dir = nums[i] > 0;

            int slow = i;
            int fast = i;

            while(true){
                int nextSlow = ((slow + nums[slow]) % n + n) % n;

                if((nums[slow] > 0) != dir || nextSlow == slow)
                    break;

                slow = nextSlow;
                int nextFast = ((fast + nums[fast]) % n + n) % n;

                if((nums[fast] > 0) != dir || nextFast == fast)
                    break;
                int nextFast2 = ((nextFast + nums[nextFast]) % n + n) % n;

                if((nums[nextFast] > 0) != dir || nextFast2 == nextFast)
                    break;

                fast = nextFast2;

                if(slow == fast)
                    return true;
            }
        }

        return false;
    }
};