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
    TreeNode* make(vector<int>&inorder, int inStr, int inEnd, vector<int>&preorder, int preStr, int preEnd, map<int, int>&inmap){
        if(inStr > inEnd || preStr > preEnd) return NULL;
        TreeNode* root = new TreeNode(preorder[preStr]);
        int inRoot = inmap[root->val];
        int leftside = inRoot - inStr;

        root->left = make(inorder, inStr, inRoot-1, preorder, preStr+1, preStr+leftside, inmap);
        root->right = make(inorder, inRoot+1, inEnd, preorder, preStr+leftside+1, preEnd, inmap);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int inEnd = inorder.size();
        map<int, int>inmap;
        for(int i = 0;i<inEnd;i++) inmap[inorder[i]] = i;
        return make(inorder, 0, inEnd, preorder, 0, preorder.size()-1, inmap);
    }
};