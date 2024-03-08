class Solution {
public:
    void flatten(TreeNode* root) {

        if(!root || (!root->left && !root->right)){
            return ;
        }

        stack<TreeNode*> s; // for -> {node_to_be_pushed}
        s.push(root);
        TreeNode* it = root;

        while(!s.empty()){
            auto node = s.top();
            s.pop();

            if(node->right){
                s.push(node->right);
            }
            if(node->left){
                s.push(node->left);
            }

            it->right = node;
            it->left = NULL;
            it = it->right;
        }

    }
};