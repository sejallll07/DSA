class NumArray {
public:
    vector<int> arr;
    NumArray(vector<int>& nums) {
        arr = nums;
        
    }
    
    int sumRange(int left, int right) {
        int sum = 0;
        vector<int>pref;
        pref.push_back(0);
        for(int i=0;i<arr.size();i++){
            sum += arr[i];
            pref.push_back(sum);
        }

        return pref[right+1] - pref[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */