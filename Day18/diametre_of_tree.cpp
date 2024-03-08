class Solution {
private:
    int solve(TreeNode* root, int & dia){
        if(!root){
            return 0 ;
        }

        int left = solve(root->left, dia);
        int right = solve(root->right, dia);

        dia = max(dia, left+right);

        return 1 + max(left,right);
    }

    int height(TreeNode* root) {
        int dia = 0; 
        solve(root, dia);
        return dia;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        return height(root);
    }
};