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

    TreeNode* bfstomapParents(TreeNode* root, map<TreeNode*,TreeNode*>&mpp,int start){
        queue<TreeNode*>q;
        q.push(root);
        TreeNode* res;
        while(!q.empty()){
            TreeNode* node = q.front();
            if(node->val == start) res = node;
            q.pop();
            if(node->left){
                mpp[node->left] = node;
                q.push(node->left);
            }
            if(node->right){
                mpp[node->right]=node;
                q.push(node->right);

            }
        }

        return res;


    }


    int amountOfTime(TreeNode* root, int start) {
    map<TreeNode* , TreeNode*>mpp;
    TreeNode* target = bfstomapParents(root , mpp , start);
    int maxi = findmaxDist(mpp,target);
    return maxi;

    }

    int findmaxDist(map<TreeNode*,TreeNode*>&mpp , TreeNode*&target){
        queue<TreeNode*>q;
        map<TreeNode* , int>vis;
        vis[target]=1;
        q.push(target);
        int maxi =0;

        while(!q.empty()){
            int sz = q.size();
            int inf = 0;
            for(int i=0;i<sz;i++){
                auto node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    inf = 1;
                    vis[node->left] =1;
                    q.push(node->left);
                }
                if(node->right && !vis[node->right]){
                    inf=1;
                    vis[node->right]=1;
                    q.push(node->right);
                }

                if(mpp[node] && !vis[mpp[node]]){
                    inf =1;
                    vis[mpp[node]] =1;
                    q.push(mpp[node]);
                }
            }
            if(inf) maxi++;
        }

        return maxi;

    }

};