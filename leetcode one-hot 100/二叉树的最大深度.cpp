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
    int maxDepth(TreeNode* root) {
        if(root==nullptr) return 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<pair<TreeNode*,int>> depth;
        int idx=0;
        depth.push_back({root,1});
        while(!q.empty()) {
            TreeNode* cur=q.front();
            q.pop();
            if(cur->left) {depth.push_back({cur->left,depth[idx].second+1});q.push(cur->left);}
            if(cur->right) {depth.push_back({cur->right,depth[idx].second+1});q.push(cur->right);}
            idx++;
        }
        int res=1;
        for(int i=0;i<depth.size();i++){
            if(depth[i].second>1) res=depth[i].second;
        }
        return res;
    }
};
