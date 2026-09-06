class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {

        int i = 0;
        while (i < fruits.size()) {

            int ind = -1;
            for (int j = 0; j < baskets.size(); j++) {

                if (baskets[j] >= fruits[i]) {
                    ind = j;
                    break;
                }
            }

            if (ind != -1) {
                baskets.erase(baskets.begin() + ind);
                fruits.erase(fruits.begin() + i);
            }
            else {
                i++;
            }
        }

        return fruits.size();
    }
};