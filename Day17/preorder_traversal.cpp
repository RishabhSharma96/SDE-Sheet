// recursive
class Solution {
public:

void solve(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return ;
        }
        ans.push_back(root->val) ;
        solve(root->left,ans) ;
        solve(root->right,ans) ;
    }

    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        solve(root,ans);
        return ans ;
    }
};


// iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s; // for -> {node_to_be_pushed}
        vector<int> ans;

        if(!root){
            return ans;
        }

        s.push(root);
        while(!s.empty()){
            auto node = s.top();
            s.pop();
            ans.push_back(node->val);

            if(node->right){
                s.push(node->right);
            }
            if(node->left){
                s.push(node->left);
            }
        }

        return ans;
    }
};