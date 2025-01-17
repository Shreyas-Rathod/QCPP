/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        if(!root) return res;
        //find parents
        map<TreeNode*, TreeNode*>parmap;
        queue<TreeNode*>qp;
        TreeNode* p;
        qp.push(root);
        parmap[root] = NULL;
        int size = 0;
        set<int>s;

        while(!qp.empty()){
            size = qp.size();
            for(int i = 0;i<size;i++){
                p = qp.front();
                qp.pop();
                if(p->left){
                    parmap[p->left] = p;
                    qp.push(p->left);
                }
                if(p->right){
                    parmap[p->right] = p;
                    qp.push(p->right);
                }
            }
        }

        // find_down
        queue<pair<TreeNode*, int>>q;
        q.push({target, 0});

        while(!q.empty()){
            size = q.size();
            for(int i = 0;i<size;i++){
                auto temp = q.front();
                q.pop();
                p = temp.first;
                if(s.count(p->val)) continue;
                if(temp.second == k) res.push_back(p->val);
                else{
                    if(p->left) q.push({p->left, temp.second+1});
                    if(p->right) q.push({p->right, temp.second+1});
                    if(parmap[p]) q.push({parmap[p], temp.second+1});
                }
                s.insert(p->val);
            }
        }

        return res;
    }
};