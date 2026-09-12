class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>dup = matrix;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                matrix[i][j] = dup[n-(j+1)][i];
            }
        }
    }

};