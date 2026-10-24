class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>ans(n , 0);
        for(auto it :bookings){
            int first = it[0];
            int second = it[1];
            while (first <= second) {
                ans[first - 1] += it[2];
                first++;
            }
        }


        return ans;
    }
};