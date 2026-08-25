
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        std::vector<std::string> result;
        int n = nums.size();
        
        for (int i = 0; i < n; i++) {
            int start = i;
        
            while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
                i++;
            }
            if (start == i) {
                result.push_back(std::to_string(nums[start]));
            } else {
                result.push_back(std::to_string(nums[start]) + "->" + std::to_string(nums[i]));
            }
        }
        
        return result;
    }
};
