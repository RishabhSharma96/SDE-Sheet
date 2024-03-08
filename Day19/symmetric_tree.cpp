class Solution {
public:

    bool solve(TreeNode* p, TreeNode* q){

        if(!p && !q) return true;
        if(!p && q) return false;
        if(p && !q) return false;
        if(p->val != q->val){
            return false;
        }

        return solve(p->right,q->left) && solve(p->left,q->right);
    }

    bool isSymmetric(TreeNode* root) {
        return solve(root->left, root->right) ;
    }
};