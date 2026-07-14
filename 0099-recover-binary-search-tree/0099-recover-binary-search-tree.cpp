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
    void recoverTree(TreeNode* root) {
        TreeNode* first =  nullptr;
        TreeNode* middle = nullptr;
        TreeNode* last = nullptr;
        TreeNode* prev = new TreeNode(INT_MIN);
        int cnt =0;
        traversal(root , first , middle , last , prev , cnt );
        if(cnt == 2) swap(first->val , last->val);
        if(cnt==1) swap(first->val , middle->val);

    }

    void traversal(TreeNode* root , TreeNode*&first , TreeNode*&middle ,TreeNode*&last , TreeNode*&prev , int&cnt){
        if(root==NULL)return;

        traversal(root->left , first , middle , last , prev , cnt);
        if(root->val < prev->val){
            cnt++;

            if(cnt == 1){
                first = prev;
                middle = root;
            }
            else{
                last = root;
            }
        }

        prev = root;
        traversal(root->right , first , middle , last , prev , cnt);
    }
};