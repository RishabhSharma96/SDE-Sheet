class Solution {
private:
    TreeNode* helper(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root){
            return NULL;
        }

        if(root == q || root == p){
            return root;
        }

        auto left = helper(root->left, p, q);
        auto right = helper(root->right, p, q);

        if(!left && !right){
            return NULL;
        }
        else if(left && !right){
            return left;
        }
        if(!left && right){
            return right;
        }
        return root;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return helper(root,p,q);
    }
};