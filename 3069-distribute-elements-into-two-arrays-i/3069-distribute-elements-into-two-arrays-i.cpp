class Solution {
public:
    vector<int> resultArray(vector<int>& nums) {
        vector<int>arr1;
        vector<int>arr2;
        int ops =0;
        for(int i=0;i<nums.size();i++){
            if(ops<2){
                if(i==0){
                    arr1.push_back(nums[i]);
                    
                }else{
                    arr2.push_back(nums[i]);
                }
            }else{
                if(arr1[arr1.size()-1]>arr2[arr2.size()-1]){
                    arr1.push_back(nums[i]);
                }else{
                    arr2.push_back(nums[i]);
                }
            }
            ops++;
        }

        
        for(int i=0;i<arr2.size();i++){
            arr1.push_back(arr2[i]);
        }

        return arr1;
    }
};