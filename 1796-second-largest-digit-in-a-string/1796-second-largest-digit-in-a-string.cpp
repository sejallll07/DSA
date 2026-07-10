class Solution {
public:
    int secondHighest(string s) {
        int first_max = -1;
        int second_max = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]>=48 && s[i]<=57){
                if(s[i]-'0' > first_max){
                    second_max = first_max;
                    first_max = s[i]-'0';
                }
                
                else if(s[i]-'0'<first_max && s[i]-'0'>second_max){
                    second_max = s[i]-'0';
                }
            }            
        }
        return second_max;
    }
};