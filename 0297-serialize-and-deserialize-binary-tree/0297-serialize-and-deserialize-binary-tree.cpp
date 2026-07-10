/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    
    string serialize(TreeNode* root ) {
       if(!root) return "";

       string s = "";
       queue<TreeNode*> q;
       q.push(root);
       while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL) {
                s.append("#,");
            }
            else{
                s.append(to_string(node->val) + ',');
            }
            if(node != NULL){
                q.push(node->left);
                q.push(node->right);
            }
       }
       return s;
    }

    
    TreeNode* deserialize(string data) {
        if(data.empty()) return NULL;
        
        stringstream s(data);
        string str;
        getline(s, str, ',');
        
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            
            
            if(getline(s, str, ',')) {
                if(str == "#"){
                    node->left = NULL;
                } else if(!str.empty()) { 
                    TreeNode* leftnode = new TreeNode(stoi(str));
                    node->left = leftnode;
                    q.push(leftnode);
                }
            }

            
            if(getline(s, str, ',')) {
                if(str == "#"){ 
                    node->right = NULL; 
                } else if(!str.empty()) {
                    TreeNode* rightnode = new TreeNode(stoi(str));
                    node->right = rightnode;
                    q.push(rightnode);
                }
            }
        }

        return root;
    }
};
