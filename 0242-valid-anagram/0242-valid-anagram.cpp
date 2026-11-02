class Solution {
public:
    bool isAnagram(string s, string t) {
        int n = s.size();
        int k = t.size();
        if(k != n)return false;

        vector<int>sfreq(26 , 0);
        vector<int>tfreq(26 , 0);

        for(int i=0;i<k;i++){
            tfreq[t[i]-'a']++;
        }

        for(int i=0;i<k;i++){
            sfreq[s[i]-'a']++;
        }

        if(sfreq==tfreq){
            return true;
        }else{
            return false;
        }
    }
};