class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 && n==1)return 1;
        vector<vector<int>>dp(m , vector<int>(n, -1));
        dp[0][0] = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[0][0] = 1;
                else{
                    if(i>0 && j>0){
                        int up = dp[i-1][j];
                        int left = dp[i][j-1];

                        dp[i][j] = up+left;
                    }
                }

                
            }
        }

        return 0-dp[m-1][n-1];
    }
};