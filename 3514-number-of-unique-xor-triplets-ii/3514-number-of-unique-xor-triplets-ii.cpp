class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<bool> pref1(MAXX, false);
        vector<bool> pref2(MAXX, false);
        vector<bool> ans(MAXX, false);

        for (int a : nums) {
            pref1[a] = true;

            vector<int> new2;
            for (int x = 0; x < MAXX; x++) {
                if (pref1[x])
                    new2.push_back(x ^ a);
            }

            for (int v : new2)
                pref2[v] = true;
            for (int x = 0; x < MAXX; x++) {
                if (pref2[x])
                    ans[x ^ a] = true;
            }
        }

        int count = 0;
        for (bool x : ans)
            if (x) count++;

        return count;
    }
};