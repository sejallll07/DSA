/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL) return NULL;

        while((p->val < root->val && q->val < root->val) || (p->val > root->val && q->val > root->val)){
            if(p->val < root->val && q->val < root->val){
                root = root->left;
            }

            if(p->val > root->val && q->val > root->val){
                root= root->right;
            }

        }

        return root;
    }
};