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
TreeNode* solve(TreeNode* root,TreeNode* p,TreeNode* q){
    if(root==NULL){
        return NULL;
    }

    int curr=root->val;
    if(curr<p->val && curr<q->val){
        return solve(root->right,p,q);
    }
    if(curr>p->val && curr>q->val){
        return solve(root->left,p,q);
    }

    return root;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return solve(root,p,q);
    }
};