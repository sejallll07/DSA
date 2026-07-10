class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        sort(citations.begin(),citations.end());
        for(int i=0;i<n;i++){
            int rem_papers = n-i;
            if(citations[i]>=rem_papers){
                return rem_papers;
            }
        }

        return 0;
    }
};