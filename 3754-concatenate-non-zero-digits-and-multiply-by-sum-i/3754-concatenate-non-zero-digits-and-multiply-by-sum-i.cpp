class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)return 0;
        string str="";
        long long sum = 0;
        while(n>0){
            int rem = n%10;
            n = n/10;

            if(rem!=0){
                sum += rem;
                str += to_string(rem);
            }
            
        }

        reverse(str.begin(),str.end());
        long long k = stoi(str);
        return k*sum;
    }
};