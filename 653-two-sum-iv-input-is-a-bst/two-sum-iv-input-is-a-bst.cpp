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
    bool inorder(TreeNode* root, int k, map<int, int>&mp){
        if(root == NULL) return false;
        bool l = inorder(root->left, k, mp);
        if(mp.find(k - root->val) != mp.end()) return true;
        mp[root->val] = 1;
        bool r = inorder(root->right, k, mp);
        return l || r;
    }
    bool findTarget(TreeNode* root, int k) {
        map<int, int>mp;
        if(root == NULL) return false;
        return inorder(root, k, mp);
    }
};