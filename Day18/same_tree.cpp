class Solution {
public:

    bool solve(TreeNode* p, TreeNode* q){
        if(!p && !q) return true;
        else if(!p && q) return false;
        else if(p && !q) return false;
        if(p->val != q->val) return false;
        
        return solve(p->left, q->left) && solve(p->right,q->right) ;
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        return solve(p,q);
    }
};