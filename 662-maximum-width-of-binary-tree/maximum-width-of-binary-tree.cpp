/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     long long val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(long long x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        long long width = 0, f, l, size, t;
        queue<pair<TreeNode*, long long>>q;
        pair<TreeNode*, long long>p;
        TreeNode* temp = 0;
        
        q.push({root, 1});
        while(!q.empty()){
            size = q.size();
            l  = q.front().second;
            f = q.back().second;
            width = max(width, f - l + 1);

            for(long long i = 0;i<size;i++){
                p = q.front();
                q.pop();
                temp = p.first;
                t = p.second - l;
                if(temp->left) q.push({temp->left, (long long)2*t});
                if(temp->right) q.push({temp->right, (long long)2*t+1});
            }
            
        }
        return width;
    }
};