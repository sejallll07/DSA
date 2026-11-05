class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> rowStrength;
        
        for (int i = 0; i < mat.size(); i++) {
            int sol = 0;
            for (int j = 0; j < mat[i].size(); j++) {
                if (mat[i][j] == 1) sol++;
            }
            rowStrength.push_back({sol, i});
        }
        
        sort(rowStrength.begin(), rowStrength.end());
        
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            ans.push_back(rowStrength[i].second);
        }
        
        return ans;
    }
};
