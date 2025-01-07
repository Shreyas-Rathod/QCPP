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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>level;
        queue<TreeNode*>q;
        int level_len = 0, next_len = 0, rev = 0;

        if(root == NULL) return res;
        else{
            level_len = 1;
            q.push(root);
        }

        while(true){
            while(level_len--){
                level.push_back(q.front()->val);
                if(q.front()->left) q.push(q.front()->left), next_len++;
                if(q.front()->right) q.push(q.front()->right), next_len++;
                q.pop();
            }
            if(rev) reverse(level.begin(), level.end());
            res.push_back(level);
            rev = 1 - rev;
            level.clear();
            if(next_len == 0) return res;
            level_len = next_len;
            next_len = 0;
        }

        return res;
    }
};