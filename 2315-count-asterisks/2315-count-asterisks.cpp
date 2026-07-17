class Solution {
public:
    int countAsterisks(string s) {
        int cnt = 0;
        bool inside = false;
        for (char ch : s) {
            if (ch == '|') {
                inside = !inside;      
            }
            else if (ch == '*' && !inside) {
                cnt++;
            }
        }
        return cnt;
    }
};