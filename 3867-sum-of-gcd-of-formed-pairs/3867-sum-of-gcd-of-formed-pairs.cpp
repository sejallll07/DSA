class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        vector<int> prefixgcd;
        int maxnum = INT_MIN;
        for(int i=0;i<nums.size();i++){
            maxnum = max(maxnum , nums[i]);
            prefixgcd.push_back(gcd(nums[i],maxnum));
        }
        

        sort(prefixgcd.begin(),prefixgcd.end());
        int m = prefixgcd.size();
        long long gcdsum=0;
        int l =0;
        int r= m-1;
        if(m%2==0){
            while(l<r){
                gcdsum += gcd(prefixgcd[l], prefixgcd[r]);
                l++;
                r--;
            }
        }else{
            
            int mid = l + (r-l)/2;
            while(l<mid && r>mid){
                gcdsum += gcd(prefixgcd[l],prefixgcd[r]);
                l++;
                r--;
            }
        }

        return gcdsum;
        
        

        
    }

    long long gcd(long long a, long long b){
        while(b){
            long long t = b;
            b = a % b;
            a = t;
        }
        return a;
    }
};