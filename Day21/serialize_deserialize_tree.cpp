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

private:
    void serializeHelper(TreeNode* root, string & ans){
        if(!root){
            ans += "#,";
            return;
        }

        ans += to_string(root->val) + ",";
        serializeHelper(root->left, ans);
        serializeHelper(root->right, ans);
    }

    TreeNode* deserializeHelper(stringstream & ss){
        string temp ;
        getline(ss, temp, ',');
        
        if(temp == "#"){
            return NULL;
        }

        TreeNode* newNode = new TreeNode(stoi(temp));
        newNode->left = deserializeHelper(ss);
        newNode->right = deserializeHelper(ss);

        return newNode;
    }

public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        serializeHelper(root, ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserializeHelper(ss);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));