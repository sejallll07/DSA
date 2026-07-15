class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {

        int five_den = 0;
        int ten_den = 0;
        
        for(int i=0;i<bills.size();i++){
            
            if(bills[i]==5){
                five_den++;
                
            }else if(bills[i]==10){
                if(five_den == 0){
                    return false;
                }else{
                    five_den--;
                    ten_den++;
                    
                }
                
            }else{
                
                if(five_den!=0 && ten_den!=0){
                    five_den--;
                    ten_den--;
                }else{
                    if(five_den >=3){
                        five_den -= 3;
                    }else{
                        return false;
                    }
                }
                
                

            }
        }
        return true;
    }
};