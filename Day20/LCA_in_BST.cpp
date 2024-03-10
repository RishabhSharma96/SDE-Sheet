class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* temp = root;
        if(p->val > q->val){
            swap(p,q);
        }

        TreeNode* ans = NULL;

        while(temp != NULL){
            if(p->val <= temp->val && temp->val <= q->val){
                return temp;
            }
            else if(p->val < temp->val && temp->val > q->val){
                ans = temp;
                temp = temp->left;
            }
            else{
                ans = temp;
                temp = temp->right;
            }
        }
        return ans;
    }
};