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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {

        while(root){
            int data = root->val;
            if((data >= p->val && data <= q->val) || (data <= p->val && data >= q->val))
                return root;
            if(data > p->val && data > q->val)
                root=root->left;
            else{
                root=root->right;
            }
        }
        return NULL;
    }
};
