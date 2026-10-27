#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> createGrid(int m, int n) {
        vector<string> mat(m, string(n, '#'));
        for (int j = 0; j < n; j++) {
            mat[0][j] = '.';
        }
        for (int i = 1; i < m; i++) {
            mat[i][n - 1] = '.';
        }

        return mat;
    }
};