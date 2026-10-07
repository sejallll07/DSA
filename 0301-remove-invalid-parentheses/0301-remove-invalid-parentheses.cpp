class Solution {
public:
    vector<string> ans;

    void remove(string s, int start, int lremove, int rremove) {

        if (lremove == 0 && rremove == 0) {
            int balance = 0;

            for (int i = 0; i < s.size(); i++) {
                if (s[i] == '(')
                    balance++;

                else if (s[i] == ')') {
                    balance--;

                    if (balance < 0)
                        return;
                }
            }

            if (balance == 0)
                ans.push_back(s);

            return;
        }

        for (int i = start; i < s.size(); i++) {

            if (i > start && s[i] == s[i - 1])
                continue;

            if (lremove + rremove > s.size() - i)
                return;

            if (lremove > 0 && s[i] == '(') {
                remove(
                    s.substr(0, i) + s.substr(i + 1),
                    i,
                    lremove - 1,
                    rremove
                );
            }

            if (rremove > 0 && s[i] == ')') {
                remove(
                    s.substr(0, i) + s.substr(i + 1),
                    i,
                    lremove,
                    rremove - 1
                );
            }
        }
    }

    vector<string> removeInvalidParentheses(string s) {

        int lremove = 0;
        int rremove = 0;

        for (char c : s) {

            if (c == '(') {
                lremove++;
            }

            else if (c == ')') {

                if (lremove > 0)
                    lremove--;
                else
                    rremove++;
            }
        }

        remove(s, 0, lremove, rremove);

        return ans;
    }
};