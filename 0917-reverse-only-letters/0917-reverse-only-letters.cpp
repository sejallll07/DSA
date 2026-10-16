class Solution {
public:
    string reverseOnlyLetters(string s) {

        int n = s.size();
        int i=0;
        int j= n-1;
        while(i<j){
            bool lflag = (s[i]>=65 && s[i]<=90)||(s[i]>=97 && s[i]<=122);
            bool rflag = (s[j]>=65 && s[j]<=90)||(s[j]>=97 && s[j]<=122);

            if(lflag && rflag){
                swap(s[i],s[j]);
                i++;
                j--;
            }else if(lflag && !rflag){
                j--;
            }else{
                i++;
            }
        }

        return s;
    }
};