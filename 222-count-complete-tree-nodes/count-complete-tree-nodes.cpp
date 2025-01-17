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
    int sum = 0;
    void cntnodes(TreeNode* root){
        if(!root) return;
        sum++;
        cntnodes(root->left);
        cntnodes(root->right);
    }
    int countNodes(TreeNode* root) {
        cntnodes(root);
        return sum;
    }
};