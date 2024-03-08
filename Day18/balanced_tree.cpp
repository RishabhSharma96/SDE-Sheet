class Solution {
private:
    int solve(TreeNode* root){
        if(!root){
            return 0 ;
        }

        int left = solve(root->left);
        int right = solve(root->right);

        if(abs(left-right) > 1){
            return 1e8;
        }

        return 1 + max(left,right);
    }

public:
    bool isBalanced(TreeNode* root) {
        return solve(root) >= 1e8 ? false : true;
    }
};