class BSTIterator {
    std::stack<TreeNode*> st;
    bool reverse;  // true means reverse in-order
public:
    BSTIterator(TreeNode* root, bool isReverse) : reverse(isReverse) {
        pushAll(root);
    }

    bool hasNext() {
        return !st.empty();
    }

    int next() {
        TreeNode* temp = st.top();
        st.pop();
        if (!reverse) {
            pushAll(temp->right);
        } else {
            pushAll(temp->left);
        }
        return temp->val;
    }

private:
    void pushAll(TreeNode* node) {
        while (node != nullptr) {
            st.push(node);
            node = reverse ? node->right : node->left;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if (!root) return false;

        BSTIterator leftIter(root, false);
        BSTIterator rightIter(root, true);

        int i = leftIter.next();
        int j = rightIter.next();

        while (i < j) {
            int sum = i + j;
            if (sum == k) return true;
            else if (sum < k) {
                if (leftIter.hasNext()) i = leftIter.next();
                else break;
            } else {
                if (rightIter.hasNext()) j = rightIter.next();
                else break;
            }
        }
        return false;
    }
};
