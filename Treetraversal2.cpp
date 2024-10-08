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
vector<vector<int>> getTreeTraversal(TreeNode *root){
    // Write your code here.
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    vector<vector<int>> ans;
    if(root==NULL){
        ans.push_back(inorder);
        ans.push_back(preorder);
        ans.push_back(postorder);
        return ans;
    }

    stack<pair<TreeNode*,int>> st;
    st.push({root,1});
    while(!st.empty()){
        auto it=st.top();
        st.pop();
        if(it.second==1){
            preorder.push_back(it.first->data);
            it.second=2;
            st.push(it);
            if(it.first->left) st.push({it.first->left,1});
        }

        else if(it.second==2){
            inorder.push_back(it.first->data);
            it.second=3;
            st.push(it);
            if(it.first->right) st.push({it.first->right,1});
        }

        else{
            postorder.push_back(it.first->data);
        }
    }

    ans.push_back(inorder);
    ans.push_back(preorder);
    ans.push_back(postorder);

    return ans;
}