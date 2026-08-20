class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        priority_queue<pair<int , pair<int , int>> , vector<pair<int,pair<int , int>>> , greater<pair<int , pair<int , int>>>>pq;

        int n = heights.size();
        int m = heights[0].size();

        vector<vector<int>>dist(n , vector<int>(m , 1e9));
        dist[0][0] =0;
        int drow[] = {-1 , 0 , 1 ,0};
        int dcol[] ={0 , 1, 0 , -1};
        pq.push({0 , {0 , 0}});
        while(!pq.empty()){
            auto it = pq.top();
            pq.pop();
            int diff = it.first;
            int r = it.second.first;
            int c = it.second.second;
            if(r==n-1 && c==m-1)return diff;
            for(int i=0;i<4;i++){
                int row = r+drow[i];
                int col = c+dcol[i];
                if(row>=0 && row<n && col>=0 && col<m ){
                    int neweffort = max(abs(heights[r][c] - heights[row][col]) , diff);
                    if(neweffort<dist[row][col]){
                        dist[row][col] = neweffort;
                        pq.push({dist[row][col] ,{row , col}});
                    }
                }
            }


        }
        return 0;
    }
};