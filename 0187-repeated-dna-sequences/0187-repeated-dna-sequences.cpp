class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        map<string , int>mpp;
        int n = s.size();
        for(int i=0;i<=n-10;i++){
            mpp[s.substr(i,10)]++;
        }
        vector<string>ans;
        for(auto it:mpp){
            if(it.second > 1){
                ans.push_back(it.first);
            }
        }

        return ans;
    }
};