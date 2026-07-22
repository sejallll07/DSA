class Solution {
    
public:

    struct cmp {
        bool operator()(const string &a, const string &b) const {
            if (a.size() == b.size())
                return a > b;
            return a.size() > b.size();
        }
    };
    
    int K;
    string kthLargestNumber(vector<string>& nums, int k) {

        priority_queue<string , vector<string> , cmp>minh;
        K = k;
        for(int i=0;i<nums.size();i++){
            minh.push(nums[i]);
            if(minh.size()>K){
                minh.pop();
            }
        }

        return minh.top();
        
    }
};