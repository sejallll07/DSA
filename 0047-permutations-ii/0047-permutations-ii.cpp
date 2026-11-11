class Solution {
public:

    void solve(vector<int>& nums,
               vector<int>& temp,
               vector<bool>& visited,
               vector<vector<int>>& ans) {

        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i = 0; i < nums.size(); i++) {
            if(visited[i]) continue;
            if(i > 0 && nums[i] == nums[i-1]
                      && !visited[i-1]) {
                continue;
            }
            visited[i] = true;
            temp.push_back(nums[i]);
            solve(nums, temp, visited, ans);
            temp.pop_back();
            visited[i] = false;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {

        sort(nums.begin(), nums.end());

        vector<vector<int>> ans;
        vector<int> temp;
        vector<bool> visited(nums.size(), false);

        solve(nums, temp, visited, ans);

        return ans;
    }
};