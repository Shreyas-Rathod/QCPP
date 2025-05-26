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
    void fun(TreeNode* root, int num){
        if(root->val > num){
            if(root->left) fun(root->left, num);
            else root->left = new TreeNode(num);
        } 
        else{
            if(root->right) fun(root->right, num);
            else root->right = new TreeNode(num);
        }
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        if(preorder.size() == 0) return NULL;
        TreeNode* root = new TreeNode(preorder[0]);
        for(int i = 1;i<preorder.size();i++){
            fun(root, preorder[i]);
        }
        return root;
    }
};