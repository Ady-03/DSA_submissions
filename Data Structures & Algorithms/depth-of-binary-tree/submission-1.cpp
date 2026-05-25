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
    void solve(TreeNode* root, int depth,int& maxdepth){
        if(root == NULL){
            return;
        }
        maxdepth = max(depth,maxdepth);
        solve(root->left,depth+1, maxdepth);
        solve(root->right, depth+1, maxdepth);
        return;
    }
public:
    int maxDepth(TreeNode* root) {
        if(root == NULL)
            return 0;
        int depth = 1;
        solve(root, depth, depth);
        return depth;
    }
};
