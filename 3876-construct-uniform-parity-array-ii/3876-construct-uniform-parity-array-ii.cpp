class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();
        int min_ev = INT_MAX;
        int min_od = INT_MAX;

        if(n==1)return true;

        for(int i=0;i<n;i++){
            if(nums1[i]%2==0){
                min_ev = min(min_ev , nums1[i]);
            }else{
                min_od = min(min_od , nums1[i]);
            }
        }

        if(min_ev < min_od && min_od != INT_MAX)return false;

        return true;
    }
};