class Solution {
public:

    bool solve(TreeNode* root, TreeNode* mini, TreeNode* maxi){

        if(!root){
            return true;
        }

        if(mini && root->val <= mini->val || maxi && root->val >= maxi->val){
            return false;
        }
        return solve(root->left,mini,root) && solve(root->right,root,maxi);

    }

    bool isValidBST(TreeNode* root) {
        return solve(root,NULL,NULL);
    }
};