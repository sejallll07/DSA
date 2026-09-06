class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
       long long lsum =0;
       long long rsum =0;
       for(int l=0;l<k;l++){
        lsum += cardPoints[l];
       }

       long long max_points = INT_MIN;
       max_points = max(lsum+rsum , max_points);
       int n = cardPoints.size();
       int l = k-1;
       int r = n-1;
       while(l>=0){
        lsum -= cardPoints[l];
        l--;
        rsum += cardPoints[r];
        r--;
        max_points = max(lsum+rsum , max_points);
        
       }

       return max_points;
    }
};