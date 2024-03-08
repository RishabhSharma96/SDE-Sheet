class Solution {
public:

    void solve(TreeNode* root, vector<string>& ans, string helper){

        if(!root->left && !root->right){
            helper += to_string(root->val);
            ans.push_back(helper);
            return ;
        }

        helper += to_string(root->val) + "->";

        if(root->left){
            solve(root->left, ans, helper);
        }
        if(root->right){
            solve(root->right, ans, helper);
        }
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if(!root){
            return ans ;
        }
        solve(root, ans, "");
        return ans;
    }
};