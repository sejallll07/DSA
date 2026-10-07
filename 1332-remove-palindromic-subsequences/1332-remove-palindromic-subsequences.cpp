class Solution {
public:
    int removePalindromeSub(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());

        if (s == rev)
            return 1;

        return 2;
    }
};