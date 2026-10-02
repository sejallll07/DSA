class Solution {
public:
    // bool isvalid(string s){
    //     stack<int>st;
    // }
    void solve(int n , vector<string>&ans , string s , int openbrack , int closebrack){
        
        if(openbrack == n && closebrack==n){
            ans.push_back(s);
            s = "";
            return;
        }

        if(openbrack<n){
            s += '(';
            solve(n , ans , s , openbrack+1 , closebrack);
            s.pop_back();
        }
        if(closebrack<n && closebrack<openbrack){
            s += ')';
            solve(n , ans , s , openbrack , closebrack+1);
            s.pop_back();
        }
        
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string s = "(";
        solve(n , ans , s , 1, 0);

        return ans;
    }
};