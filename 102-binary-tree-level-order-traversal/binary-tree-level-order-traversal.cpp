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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<int>level;
        vector<vector<int>>res;
        queue<TreeNode*>st;
        int level_len = 0, next_len = 0;

        if(root == NULL) return res;
        else{
            level_len = 1;
            st.push(root);
        }

        while(true){
            while(level_len--){
                level.push_back(st.front()->val);
                if(st.front()->left != NULL) st.push(st.front()->left), next_len++;
                if(st.front()->right != NULL) st.push(st.front()->right), next_len++;
                st.pop();
            }
            res.push_back(level);
            level.clear();
            if(next_len == 0) return res;
            level_len = next_len;
            next_len = 0;
        }

        return res;
    }
};