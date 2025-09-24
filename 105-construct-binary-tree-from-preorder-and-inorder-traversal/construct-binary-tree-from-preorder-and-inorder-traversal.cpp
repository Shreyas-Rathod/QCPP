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
    TreeNode* fun(vector<int>&inorder, int instr, int inend, vector<int>&preorder, int prestr, int prend, unordered_map<int, int>&mp){
        if(instr > inend || prestr > prend) return NULL;
        TreeNode *root = new TreeNode(preorder[prestr]);
        int idx = mp[preorder[prestr]];
        int leftside = idx - instr;
        root->left = fun(inorder, instr, idx-1, preorder, prestr+1, prestr+leftside, mp);
        root->right = fun(inorder, idx+1, inend, preorder, prestr+leftside+1, prend, mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int>mp;
        int n = inorder.size(), m = preorder.size();
        for(int i = 0;i<n;i++) mp[inorder[i]] = i;
        return fun(inorder, 0, n-1, preorder, 0, m-1, mp);
    }
};