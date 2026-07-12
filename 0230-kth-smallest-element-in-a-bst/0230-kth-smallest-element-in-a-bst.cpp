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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0;
        int small;
        helper(root , k , cnt , small);
        return small;

    }
    void helper(TreeNode* root , int k , int&cnt , int&small){
        if(root==NULL) return;

        helper(root->left , k , cnt , small);
        cnt++;
        if(cnt==k) {
            small  = root->val;
            
        }
        helper(root->right , k , cnt , small);

       
    }
};