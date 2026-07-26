class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int , int>>maxh;
        for(int i=0;i<points.size();i++){
            int dist = pow(abs(points[i][0]),2) + pow(abs(points[i][1]) , 2);
            maxh.push({dist , i});

            if(maxh.size()>k) maxh.pop();

        }

        vector<vector<int>>ans;
        while(maxh.size()>0){
            ans.push_back(points[maxh.top().second]);
            maxh.pop();

        }
        return ans;

    }
};