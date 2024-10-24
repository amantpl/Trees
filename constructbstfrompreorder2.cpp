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
TreeNode* solve(vector<int>& preorder,int& index,int upperbound){
    if(index==preorder.size() || preorder[index]>upperbound){
        return NULL;
    }

    TreeNode* root=new TreeNode(preorder[index++]);

    root->left=solve(preorder,index,root->val);

    root->right=solve(preorder,index,upperbound);

    return root;
}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index=0;
        return solve(preorder,index,INT_MAX);
    }
};