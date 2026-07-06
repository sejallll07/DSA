class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int start = 0;
        int end = 0;
        int n = intervals.size();
        int cnt =n;
        sort(intervals.begin(), intervals.end(),
            [](vector<int>& a, vector<int>& b){
                if(a[0] == b[0])
                    return a[1] > b[1];   
                return a[0] < b[0];
            });
        for(int i=0;i<intervals.size();i++){
            if(intervals[i][0]>=start && intervals[i][1]<=end){
                cnt --;
            }else{
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }

        return cnt;
    }
};