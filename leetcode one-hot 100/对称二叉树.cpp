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
    bool isSymmetric(TreeNode* root) {
        queue<TreeNode*> q;
        queue<TreeNode*> q_next;
        TreeNode* tmp=new TreeNode(root->val);
        q.push(root);
        q_next.push(tmp);
        while(!q.empty()){
            TreeNode* cur=q.front();q.pop();
            TreeNode* cur1=q_next.front();q_next.pop();
            if(cur->left){TreeNode* t1=new TreeNode(cur->left->val);cur1->right=t1;q_next.push(t1);q.push(cur->left);
            }
            if(cur->right){TreeNode* t1=new TreeNode(cur->right->val);cur1->left=t1;q_next.push(t1);q.push(cur->right);
            }
        }
        q.push(root);
        q_next.push(tmp);
        while(!q.empty()){
            TreeNode* cur=q.front();q.pop();
            TreeNode* cur1=q_next.front();q_next.pop();
            if(cur->left&&cur1->left&&cur->right&&cur1->right) {
                if(cur->left->val!=cur1->left->val||cur->right->val!=cur1->right->val) return false;
                q.push(cur->left);q.push(cur->right);
                q_next.push(cur1->left);q_next.push(cur1->right);
            }
            else if(cur->right&&cur1->right&&cur->left==nullptr&&cur1->left==nullptr){
                if(cur->right->val!=cur1->right->val) return false;
                q.push(cur->right);q_next.push(cur1->right);
            }
            else if(cur->left&&cur1->left&&cur->right==nullptr&&cur1->right==nullptr){
                if(cur->left->val!=cur1->left->val) return false;
                q.push(cur->left);q_next.push(cur1->left);
            }
            else if(cur->left==nullptr&&cur->right==nullptr&&cur1->left==nullptr&&cur1->right==nullptr) continue;
            else return false;
        }
        return true;
    }
};
