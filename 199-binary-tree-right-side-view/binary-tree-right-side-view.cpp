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
    int height(TreeNode* root){
        if(!root) return 0;
        return 1 + max(height(root->left), height(root->right));
    }
    vector<int> rightSideView(TreeNode* root) {
        int h = height(root);
        vector<int>res(h);
        if(!root) return res;
        queue<pair<TreeNode*, int>>q;
        int x;
        TreeNode* temp;

        q.push({root, 0});
        while(!q.empty()){
            auto p = q.front();
            temp = p.first;
            q.pop();
            x = p.second;
            res[x] = temp->val;
            if(temp->left) q.push({temp->left, x+1});
            if(temp->right) q.push({temp->right, x+1});
        }

        return res;
    }
};