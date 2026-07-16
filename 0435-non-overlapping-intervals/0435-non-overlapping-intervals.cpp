class Solution {
    struct min_inter{
        int start;
        int end;
        int pos;
    };
    static bool comp(min_inter &a, min_inter &b){
        return a.end < b.end;
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<min_inter>arr(n);

        for(int i=0;i<n;i++){
            arr[i].start = intervals[i][0];
            arr[i].end = intervals[i][1];
            arr[i].pos = i;
        }

        sort(arr.begin(), arr.end(), comp);
        int end_point = arr[0].end;
        int cnt =0;
        for(int i=1;i<n;i++){

            if(arr[i].start < end_point){

                cnt++;
            }else{
                end_point = arr[i].end;
            }
        }

        return cnt;
    }
};