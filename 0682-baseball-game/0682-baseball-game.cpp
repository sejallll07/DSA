class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size();
        int score = 0;
        vector<int>dig;
        for(int i=0;i<n;i++){
            
            if(operations[i] == "+" ){
                int len = dig.size();
                if(len>=2){
                    dig.push_back(dig[len-1]+dig[len-2]);
                }
            }else if(operations[i]=="D"){
                int len = dig.size();
                dig.push_back(2*dig[len-1]);
            }else if(operations[i]=="C"){
                dig.pop_back();
            }else{
                dig.push_back(stoi(operations[i]));
            }


        }
        int sum =0;
        for(auto it:dig){
            sum += it;
        }

        return sum;
    }
};