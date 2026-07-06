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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ds;
        if(root==NULL)return ds;
        if(root->left == NULL && root->right==NULL){
            ds.push_back(to_string(root->val));
            return ds;
        }
        string str;
        solve(root , ds , str);
        return ds;


    }

    void solve(TreeNode* node , vector<string>&ds , string &str){
        if(!node) return;
        str += to_string(node->val);
        str += "->";

        if(node->left == NULL && node->right==NULL){
            str.erase(str.length()-2);
            ds.push_back(str);
            str += "->";
            str.erase(str.length()-(to_string(node->val).length() + 2));
            return;

        }

        solve(node->left , ds , str);
        solve(node->right , ds , str);
        str.erase(str.length()-(to_string(node->val).length() + 2));

    }
};