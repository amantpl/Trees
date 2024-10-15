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
TreeNode* solve(vector<int>& inorder,int instart,int inend,vector<int>& postorder,int poststart,int postend,unordered_map<int,int>& mp){
    if(instart>inend || poststart>postend){
        return NULL;
    }
    TreeNode* root=new TreeNode(postorder[postend]);
    int inroot=mp[root->val];
    int numsleft=inroot-instart;

    root->left=solve(inorder,instart,inroot-1,postorder,poststart,poststart+numsleft-1,mp);

    root->right=solve(inorder,inroot+1,inend,postorder,poststart+numsleft,postend-1,mp);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        int n=inorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        int m=postorder.size();
        int instart=0;
        int inend=n-1;
        int poststart=0;
        int postend=m-1;
        TreeNode* root=solve(inorder,instart,inend,postorder,poststart,postend,mp);

        return root;
    }
};