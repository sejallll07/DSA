class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;

        for (char i : s) {
            freq[i]++;
        }

        vector<pair<char, int>> vec(freq.begin(), freq.end());

        sort(vec.begin(), vec.end(), [](const auto& a, const auto& b) {
            if (a.second != b.second) {
                return a.second > b.second;
            }

            return a.first < b.first;
        });

        string ans = "";

        for (const auto& p : vec) {
            ans.append(p.second, p.first);
        }

        return ans;
    }
};