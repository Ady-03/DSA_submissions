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
    pair<int,bool> check(TreeNode* root){
        if(root == NULL){
            pair<int,bool> p = make_pair(0,true);
            return p;
        }
        pair<int,bool> left = check(root->left);
        pair<int,bool> right = check(root->right);
        pair<int,bool> ans;
        int height = 1 + max(left.first,right.first);
        bool balanced = (abs(left.first - right.first) <= 1) && left.second && right.second;
        return make_pair(height,balanced);
    }
public:
    bool isBalanced(TreeNode* root) {
        return check(root).second;
    }
};
