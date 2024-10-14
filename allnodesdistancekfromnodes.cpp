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
void parent_track(TreeNode* root,unordered_map<TreeNode*,TreeNode*>& parent){
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* node=q.front();
        q.pop();
        if(node->left){
            parent[node->left]=node;
        }

        if(node->right){
            parent[node->right]=node;
        }
    }
}
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> mp;
        parent_track(root,mp);

        queue<TreeNode*> q;
        q.push(target);
        unordered_map<TreeNode*,bool> vis;
        vis[target]=true;
        int current_dis=0;
        while(!q.empty()){
            int n=q.size();
            if(current_dis==k){
                break;
            }
            current_dis++;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front();
                q.pop();
                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                }

                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                }

                if(mp[node] && !vis[mp[node]]){
                    vis[mp[node]]=true;
                    q.push(mp[node]);
                }
            }

        }

        vector<int> ans;
        while(!q.empty()){
            ans.push_back(q.front()->val);
            q.pop();
        }

        return ans;

    }
};