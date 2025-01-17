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
    int countNodes(TreeNode* root) {
        int cnt = 0, size;
        queue<TreeNode*>q;
        TreeNode* p;
        if(!root) return cnt;

        q.push(root);
        while(!q.empty()){
            size = q.size();
            for(int i = 0;i<size;i++){
                p = q.front();
                q.pop();
                cnt++;
                if(p->left) q.push(p->left);
                if(p->right) q.push(p->right);
            }
        }

        return cnt;
    }
};