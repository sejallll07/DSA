class Solution {
public:
    int firstUniqChar(string s) {

        map<char, pair<int, int>> mpp;

        for(int i = 0; i < s.size(); i++) {
            mpp[s[i]].first++;
            mpp[s[i]].second = i;
        }

        for(int i = 0; i < s.size(); i++) {

            if(mpp[s[i]].first == 1) {
                return i;
            }
        }

        return -1;
    }
};