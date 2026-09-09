class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors) {
        int n = colors.size();
        int group = 0;
        for(int i=0;i<n;i++){
            if(colors[i%n]==colors[(i+2)%n] && colors[i%n]!=colors[(i+1)%n]) group++;
        }
        return group;
    }
};