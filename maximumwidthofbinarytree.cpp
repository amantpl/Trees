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
    int widthOfBinaryTree(TreeNode* root) {
        long long maxi=INT_MIN;
        queue<pair<TreeNode*,int>> q;
        q.push({root,0});
        while(!q.empty()){
            int n=q.size();
            vector<long long> res;
            long long mini=q.front().second;
            for(int i=0;i<n;i++){
            auto it=q.front();
            TreeNode* node=it.first;
            long long index=it.second-mini;
            q.pop();
            res.push_back(index);
            if(node->left){
                q.push({node->left,(long long)2*index+1});
            }
            if(node->right){
                q.push({node->right,(long long)2*index+2});
            }
            }
            maxi=max(maxi,res[res.size()-1]-res[0]+1);
        }
        return maxi;
    }
};