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
    TreeNode* make(vector<int>&inorder, int inStr, int inEnd, vector<int>&postorder, int poStr, int poEnd, map<int, int>&inmap){
        if(inStr > inEnd || poStr > poEnd) return NULL;
        TreeNode* root = new TreeNode(postorder[poEnd]);
        int inRoot = inmap[root->val];
        int rightside = inEnd - inRoot;

        root->right = make(inorder, inRoot+1, inEnd, postorder, poEnd - rightside, poEnd-1, inmap);
        root->left = make(inorder, inStr, inRoot-1, postorder, poStr, poEnd - rightside - 1, inmap); 
        
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int>inmap;
        int inEnd = inorder.size();
        for(int i = 0;i<inEnd;i++) inmap[inorder[i]] = i;
        return make(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, inmap);
    }
};