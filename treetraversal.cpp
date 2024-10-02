/*
    Following is Binary Tree Node structure:
    class TreeNode
    {
    public:
        int data;
        TreeNode *left, *right;
        TreeNode() : data(0), left(NULL), right(NULL) {}
        TreeNode(int x) : data(x), left(NULL), right(NULL) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
    };
*/
void inorder(TreeNode* root,vector<int>& res1){
    if(root==NULL){
        return ;
    }

    inorder(root->left,res1);
    res1.push_back(root->data);
    inorder(root->right,res1);
}

void preorder(TreeNode* root,vector<int>& res2){
    if(root==NULL){
        return ;
    }

    res2.push_back(root->data);
    preorder(root->left,res2);
    preorder(root->right,res2);
}

void postorder(TreeNode* root,vector<int>& res3){
    if(root==NULL){
        return ;
    }

    postorder(root->left,res3);
    postorder(root->right,res3);
    res3.push_back(root->data);
}
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<vector<int>> ans;
    vector<int> res1;
    vector<int> res2;
    vector<int> res3;
    inorder(root,res1);
    preorder(root,res2);
    postorder(root,res3);
    ans.push_back(res1);
    ans.push_back(res2);
    ans.push_back(res3);
    return ans;
}