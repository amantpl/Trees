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
TreeNode* solve(vector<int>& preorder,int pre_start,int pre_end,vector<int>& inorder,int in_start,int in_end,unordered_map<int,int>& mp){
    if(pre_start>pre_end || in_start>in_end){
        return NULL;
    }

    TreeNode* root=new TreeNode(preorder[pre_start]);
    int in_root=mp[root->val];
    int nums_left=in_root-in_start;

    root->left=solve(preorder,pre_start+1,pre_start+nums_left,inorder,in_start,in_root-1,mp);

    root->right=solve(preorder,pre_start+nums_left+1,pre_end,inorder,in_root+1,in_end,mp);

    return root;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int m=preorder.size();
        int pre_start=0;
        int pre_end=m-1;
        int in_start=0;
        int in_end=n-1;
        TreeNode* root=solve(preorder,pre_start,pre_end,inorder,in_start,in_end,mp);

        return root;
    }
};