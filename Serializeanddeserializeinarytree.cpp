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

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string t="";
        queue<TreeNode*> q;
        q.push(root);
        t+=to_string(root->val)+",";
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();
            if(node->left){
                t+=to_string(node->left->val) + ",";
                q.push(node->left);
            }else{
                t+="#,";
            }

            if(node->right){
                t+=to_string(node->right->val)+",";
                q.push(node->right);
            }else{
                t+="#,";
            }
        }
        return t;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        int n=data.size();
        if(n==0) return NULL;
        stringstream s(data);
        string str;
        getline(s,str,',');
        TreeNode* root=new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* node=q.front();
            q.pop();

            //for the left child
            getline(s,str,',');
            if(str=="#"){
                node->left=NULL;
            }else{
                TreeNode* root=new TreeNode(stoi(str));
                node->left=root;
                q.push(root);
            }

            //for the right child 
            getline(s,str,',');
            if(str=="#"){
                node->right=NULL;
            }else{
                TreeNode* root=new TreeNode(stoi(str));
                node->right=root;
                q.push(root);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));