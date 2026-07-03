/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    int diameterOfBinaryTree(TreeNode* root ) {
        int maxi = 0;
        // TreeNode* node = root;
        findmax(root , maxi);
        return maxi;
    }

    int findmax(TreeNode* node , int& maxi){
        
        if(node==NULL)return 0;
        int lh = findmax(node->left , maxi);
        int rh = findmax(node->right , maxi);
        maxi = max(maxi , lh+rh);
        return 1+max(lh,rh);
    }
};