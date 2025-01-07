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
        queue<TreeNode*>q;
        int level_len = 0, ltr = 0, index;

        if(root == NULL) return res;
        q.push(root);

        while(!q.empty()){
            level_len = q.size();
            vector<int>level(level_len);
            for(int i = 0;i<level_len;i++){
                index = ltr ? level_len - 1 - i : i;
                level[index] = q.front()->val;
                if(q.front()->left) q.push(q.front()->left);
                if(q.front()->right) q.push(q.front()->right);
                q.pop();
            }
            res.push_back(level);
            ltr = !ltr;
        }

        return res;
    }
};