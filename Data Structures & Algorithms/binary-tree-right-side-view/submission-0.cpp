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
    vector<int> rightSideView(TreeNode* root) {
        if(!root)
            return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        q.push(root);
        
        while(!q.empty()){
            int size = q.size();
            vector<int> sub;
            for(int i=0; i<size; i++){
                TreeNode* temp= q.front();
                q.pop();
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
                sub.push_back(temp->val);
            }
            ans.push_back(sub);
        }
        vector<int> real;
        for(int i=0; i<ans.size(); i++){
            real.push_back(ans[i].back());
        }
        return real;
    }
};
