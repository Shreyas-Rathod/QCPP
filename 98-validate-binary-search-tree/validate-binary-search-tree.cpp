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
    bool fun(long mini, long maxi, TreeNode* root){
        if(root == NULL) return true;
        if(root->val <= mini || root->val >= maxi) return false;
        return fun(mini, root->val, root->left) && fun(root->val, maxi, root->right);
    }
    bool isValidBST(TreeNode* root) {
        if(root == NULL) return true;
        return fun(-2147483649L, 2147483648L, root);
    }
};