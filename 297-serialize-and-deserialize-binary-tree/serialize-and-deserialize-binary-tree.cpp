/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {  
public:  
    // Serialize a tree to a single string  
    string serialize(TreeNode* root) {  
        if (!root) return "null,"; // Use "null," to represent a null node  
        return to_string(root->val) + "," + serialize(root->left) + serialize(root->right);  
    }  

    // Deserialize your encoded data to tree  
    TreeNode* deserialize(string data) {  
        // Split the data by commas  
        vector<string> nodes;  
        stringstream ss(data);  
        string s;  
        while (getline(ss, s, ',')) {  
            nodes.push_back(s);  
        }  
        
        // Reset index for deserialization  
        int index = 0;   
        return deserializeHelper(nodes, index);  
    }  

private:  
    TreeNode* deserializeHelper(const vector<string>& nodes, int& index) {  
        // Check if we've reached the end of the nodes array  
        if (index >= nodes.size() || nodes[index] == "null") {  
            index++; // Move to the next node  
            return nullptr; // Return null if "null" is found  
        }  
        
        // Create new tree node  
        TreeNode* root = new TreeNode(stoi(nodes[index++]));  
        
        // Recursively construct the left and right subtree  
        root->left = deserializeHelper(nodes, index);  
        root->right = deserializeHelper(nodes, index);  
        
        return root;  
    }  
};  

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));