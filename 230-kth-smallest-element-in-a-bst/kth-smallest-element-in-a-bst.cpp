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
    int rc, res;
    void inorder(TreeNode* root, int k){
        if(root == NULL) return;
        if(root->left) inorder(root->left, k);
        rc++;
        if(rc == k){
            res = root->val;
            return;
        }
        if(root->right) inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        rc = 0, res = 0;
        inorder(root, k);
        return res;
    }
};