class Solution {
public:
    int countPoints(string rings) {
        int n = INT_MIN;
        for(char x :rings){
            if(isdigit(x)){
                n = max(n , x-'0');
            }
        }
        vector<set<char>> ringcnt(10);
        int i= 0;
        while(i<rings.size()){
            int rod = rings[i + 1] - '0';
            char color = rings[i];
            ringcnt[rod].insert(color);
            i+=2;
        }

        int cnt = 0;
        for(int i=0;i<ringcnt.size();i++ ){
            if(ringcnt[i].size()==3){
                cnt++;
            }
        }

        return cnt;

    }
};