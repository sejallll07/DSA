class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {

        unordered_map<int, int> mpp;

        for (int x : nums)
            mpp[x]++;

        vector<pair<int, int>> freq;

        for (auto &it : mpp)
            freq.push_back(it);

        sort(freq.begin(), freq.end(),
            [](const pair<int,int>& a, const pair<int,int>& b) {
                return a.second > b.second;
            });

        vector<int> result;

        for (int i = 0; i < k; i++)
            result.push_back(freq[i].first);

        return result;
    }
};