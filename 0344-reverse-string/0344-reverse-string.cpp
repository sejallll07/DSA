class Solution {
public:
    void reverseString(vector<char>& s) {
        int l =0;
        int n = s.size();
        int r = n-1;

        while(l<r){
            swap(s[l] , s[r]);

            l++;
            r--;
        }

       

        
    }
};