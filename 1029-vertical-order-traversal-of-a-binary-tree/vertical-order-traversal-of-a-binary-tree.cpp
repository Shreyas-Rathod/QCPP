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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<pair<TreeNode*, pair<int, int>>>q;
        map<int, map<int, multiset<int>>>mp;
        TreeNode *temp;
        int lvl = 0, col = 0;
        q.push({root,{lvl, col}});

        while(!q.empty()){
            auto t = q.front();
            q.pop();

            temp = t.first;
            lvl = t.second.first;
            col = t.second.second;

            mp[col][lvl].insert(temp->val);

            if(temp->left) q.push({temp->left, {lvl+1, col-1}});
            if(temp->right) q.push({temp->right, {lvl+1, col+1}});
        }

        vector<vector<int>>res;

        for(auto p : mp){
            vector<int>col;
            for(auto q : p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            res.push_back(col);
        }

        return res;
    }
};