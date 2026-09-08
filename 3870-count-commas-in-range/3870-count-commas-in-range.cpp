class Solution {
public:
    int countCommas(int n) {
        int comma =0;
        while(n>=1000){
            if(n/1000>0)comma++;
            n--;
        }
        return comma;
    }
};