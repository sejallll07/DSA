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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int l =0;
        int n = nums.size();
        int r = n-1;
        return buildTree(nums , l , r);
    }

    TreeNode* buildTree( vector<int>&in , int l , int r){
        
        if(l>r) return nullptr;
        int mid = l + (r-l)/2;
        TreeNode* root = new TreeNode(in[mid]);
        root->left = buildTree(in , l , mid-1);
        root->right = buildTree(in , mid+1 , r);

        return root;

    }
};