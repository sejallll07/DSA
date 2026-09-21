class Solution {
public:

    void solve(vector<int>& digits, vector<int>& used,
               int count, int number, set<int>& ans) {

        if(count == 3) {
            if(number % 2 == 0) {
                ans.insert(number);
            }
            return;
        }

        for(int i = 0; i < digits.size(); i++){
            if(used[i])
                continue;
            if(count == 0 && digits[i] == 0)
                continue;

            used[i] = 1;

            solve(digits, used,count + 1,number * 10 + digits[i],ans);
            used[i] = 0;
        }
    }

    vector<int> findEvenNumbers(vector<int>& digits) {

        set<int> ans;
        vector<int> used(digits.size(), 0);
        solve(digits, used, 0, 0, ans);

        return vector<int>(ans.begin(), ans.end());
    }
};