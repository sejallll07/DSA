class Solution {
public:
    string toHex(int num) {
        if(num == 0)
            return "0";

        unsigned int n = num;
        string hex = "";
        char hexi[] = {'a','b','c','d','e','f'};

        while(n > 0) {
            int quo = n % 16;
            n = n / 16;

            if(quo >= 10)
                hex += hexi[quo - 10];
            else
                hex += to_string(quo);
        }
        reverse(hex.begin(), hex.end());
        return hex;
    }
};