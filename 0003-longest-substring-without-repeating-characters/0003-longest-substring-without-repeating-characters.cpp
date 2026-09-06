class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char , int>hash;
        int n = s.size();
        int l =0;
        int r = 0;
        int max_len = INT_MIN;
        if(s=="")return 0;
        while(r<n){
            if(hash.find(s[r]) != hash.end()){
                l = max(l , hash[s[r]] + 1);

            }     
            hash[s[r]] = r;
            max_len = max(max_len , r-l+1);
            r++;
        }

        return max_len;
    }
};