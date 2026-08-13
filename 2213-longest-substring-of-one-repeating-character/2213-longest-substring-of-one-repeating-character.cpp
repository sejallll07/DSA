class Solution {
public:

    vector<int> longestRepeating(string s, string queryCharacters,
                                 vector<int>& queryIndices) {

        set<pair<int,int>> groups;
        multiset<int> lengths;

        int n = s.size();
        int start = 0;

        for (int i = 1; i <= n; i++) {
            if (i == n || s[i] != s[i - 1]) {
                groups.insert({start, i - 1});
                lengths.insert(i - start);
                start = i;
            }
        }

        vector<int> ans;

        for (int q = 0; q < queryIndices.size(); q++) {

            int idx = queryIndices[q];
            char ch = queryCharacters[q];
            if (s[idx] == ch) {
                ans.push_back(*lengths.rbegin());
                continue;
            }
            auto it = groups.upper_bound({idx, n});
            --it;

            int l = it->first;
            int r = it->second;
            groups.erase(it);
            lengths.erase(lengths.find(r - l + 1));
            if (l < idx) {
                groups.insert({l, idx - 1});
                lengths.insert(idx - l);
            }

            if (idx < r) {
                groups.insert({idx + 1, r});
                lengths.insert(r - idx);
            }
            s[idx] = ch;
            int newL = idx;
            int newR = idx;
            auto right = groups.lower_bound({idx, -1});

            if (right != groups.begin()) {

                auto left = prev(right);

                if (left->second == idx - 1 &&
                    s[left->first] == ch) {

                    newL = left->first;

                    lengths.erase(
                        lengths.find(left->second - left->first + 1)
                    );

                    groups.erase(left);
                }
            }
            right = groups.lower_bound({idx, -1});

            if (right != groups.end() &&
                right->first == idx + 1 &&
                s[right->first] == ch) {

                newR = right->second;

                lengths.erase(
                    lengths.find(right->second - right->first + 1)
                );

                groups.erase(right);
            }
            groups.insert({newL, newR});
            lengths.insert(newR - newL + 1);
            ans.push_back(*lengths.rbegin());
        }

        return ans;
    }
};