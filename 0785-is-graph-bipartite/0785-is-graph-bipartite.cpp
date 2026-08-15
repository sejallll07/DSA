class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) { 
        int n = graph.size();
        vector<int> colr(n, -1);

        for(int start = 0; start < n; start++) {
            if(colr[start] != -1)
                continue;

            queue<int> q;
            q.push(start);
            colr[start] = 0;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(int i = 0; i < graph[node].size(); i++) {
                    int neighbor = graph[node][i];

                    if(colr[neighbor] == -1) {
                        colr[neighbor] = 1 - colr[node];
                        q.push(neighbor);
                    }
                    else if(colr[neighbor] == colr[node]) {
                        return false;
                    }
                }
            }
        }

        return true;
    }
};