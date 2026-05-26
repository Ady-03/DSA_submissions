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
    bool isSame(TreeNode* root, TreeNode* sub){
        if(!root && !sub)
            return true;
        if(!root || !sub)
            return false;
        if(root->val != sub->val)
            return false;
        return isSame(root->left,sub->left) && isSame(root->right,sub->right);
    }

    bool check(TreeNode* root, TreeNode* sub){
        if(root == NULL && sub == NULL)
            return true;
        if(root == NULL && sub != NULL)
            return false;
        bool found = false;
        if(root->val == sub->val)
            found = isSame(root,sub);
        return check(root->left,sub) || check(root->right,sub) || found;
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        return check(root,subRoot);
    }
};
