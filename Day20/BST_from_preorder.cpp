class Solution {
public:

    TreeNode* solve (vector<int>& preorder, int & i, int ub){

        if(i >= preorder.size() || preorder[i] > ub) return NULL ;

        TreeNode* root = new TreeNode(preorder[i]);
        i++;

        root->left = solve(preorder,i,preorder[i-1]);
        root->right = solve(preorder,i,ub);

        return root ;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0 ;
        return solve(preorder,i,INT_MAX);
    }
};