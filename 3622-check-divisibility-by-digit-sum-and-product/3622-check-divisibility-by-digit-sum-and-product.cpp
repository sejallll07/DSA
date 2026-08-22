class Solution {
public:
    bool checkDivisibility(int n) {
        int prod = 1;
        int digsum = 0;
        int org = n;
        
        while(n>0){
            int rem = n%10;
            n = n/10;

            digsum += rem;
            prod = prod * rem;
        }

        int sum = (digsum + prod);
        return ((org%sum) == 0);


    }
};