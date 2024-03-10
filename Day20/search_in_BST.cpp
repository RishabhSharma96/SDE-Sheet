// iterative
class Solution {
public:

    TreeNode * solve(TreeNode* root, int val){

        if(!root){
            return NULL;
        }

        TreeNode* it = root;
        while(it){
            if(it->val == val){
                return it;
            }
            else if(it->val < val){
                it = it->right;
            }
            else{
                it = it->left;
            }
        }
        return NULL;        
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};




// recursive
class Solution {
public:

    TreeNode * solve(TreeNode* root, int val){

        if(root == NULL){
            return nullptr ;
        }

        if(root -> val == val){
            return root ;
        }
        else if(root->val < val){
            return solve(root->right,val);
        }
        return solve(root->left,val);
        
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};