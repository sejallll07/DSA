class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int k = p.size();
        int n = s.size();
        vector<int> ans;
        if(k>n)return ans;
        vector<int>pfreq(26 , 0);
        vector<int>sfreq(26 , 0);

        for(int i=0;i<k;i++){
            pfreq[p[i]-'a']++;
        }

        for(int i=0;i<k;i++){
            sfreq[s[i]-'a']++;
        }

        if(sfreq == pfreq) ans.push_back(0);

        for(int i=k;i<n;i++){
            sfreq[s[i-k] - 'a']--;
            sfreq[s[i]-'a']++;

            if(sfreq==pfreq) ans.push_back(i-k+1);
        }

        return ans;
    }

    
};