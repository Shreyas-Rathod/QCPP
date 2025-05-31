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
    TreeNode* ele1 = NULL;
    TreeNode* ele2 = NULL;
    TreeNode* prev = new TreeNode(INT_MIN);
    void recoverTree(TreeNode* root) {
        traverse(root);
        int temp = ele1->val;
        ele1->val = ele2->val;
        ele2->val = temp;
    };
private:
    void traverse(TreeNode* root){
        if(root == NULL) return;
        traverse(root->left);
        if(ele1 == NULL && prev->val > root->val) ele1 = prev;
        if(ele1 != NULL && prev->val > root->val) ele2 = root;
        prev = root;
        traverse(root->right);
    };
};