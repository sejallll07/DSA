/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int>in;
        ListNode* temp = head;
        while(temp!=NULL){
            
            in.push_back(temp->val);
            temp = temp->next;
        }
        int l =0;
        int n = in.size();
        int r = n-1;

        return buildTree(in , l ,r);

        
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