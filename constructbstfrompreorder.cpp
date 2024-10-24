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
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        stack<TreeNode*> st;
        TreeNode* node=new TreeNode(preorder[0]);
        st.push(node);
        int n=preorder.size();
        for(int i=1;i<n;i++){
            TreeNode* curr=new TreeNode(preorder[i]);
            if(curr->val<st.top()->val){
                st.top()->left=curr;
            }else if(curr->val>st.top()->val){
                TreeNode* parent=NULL;
                while(!st.empty() && st.top()->val<curr->val){
                    parent=st.top();
                    st.pop();
                }
                parent->right=curr;
            }
            st.push(curr);
        }
        return node;
    }
};