class Solution {
public:

    void solve(TreeNode* root, int k, int& ans, int & currCount){
        if(!root){
            return;
        }

        solve(root->left, k, ans, currCount);
        currCount++;
        if(currCount == k){
            ans = root->val;
        }
        solve(root->right, k, ans, currCount);
    }

    int kthSmallest(TreeNode* root, int k) {
        int ans = 0, currCount = 0;
        solve(root,k,ans,currCount);
        return ans;
    }
};