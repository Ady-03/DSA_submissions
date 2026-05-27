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
private:
    TreeNode* lca(TreeNode* root, TreeNode* p, TreeNode* q){
        if((root->val <= p->val && root->val >= q->val) || (root->val >= p->val && root->val <= q->val))
            return root;
        if(root->val >= p->val && root->val >= q->val)
            return lca(root->left,p,q);
        else{
            return lca(root->right,p,q);
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return lca(root,p,q);
    }
};
