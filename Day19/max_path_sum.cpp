class Solution {
public:

    int solve(TreeNode* root, int & pathsum){

        if(!root){
            return 0 ;
        }

        int left = solve(root->left, pathsum);
        if(left < 0){
            left = 0;
        }
        int right = solve(root->right, pathsum);
        if(right < 0){
            right = 0;
        }

        pathsum = max(pathsum , left+right+root->val);
        return max(left,right) + root->val ;

    }

    int maxPathSum(TreeNode* root) {
        int pathsum = INT_MIN ;
        solve(root, pathsum);
        return pathsum ;
    }
};