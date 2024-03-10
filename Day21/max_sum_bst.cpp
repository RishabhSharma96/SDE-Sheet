class Node {
public:
    int sum;
    int mini;
    int maxi;
    Node(int sum = 0, int mini = INT_MAX, int maxi = INT_MIN) {
        this->sum = sum;
        this->mini = mini;
        this->maxi = maxi;
    }
};

class Solution {
public:

    int ans = 0;
    Node helper(TreeNode* root) {
        if (!root){
            return Node(0, INT_MAX, INT_MIN);
        }
        auto lt = helper(root->left);
        auto rt = helper(root->right);
        if (root->val > lt.maxi && root->val < rt.mini) {
            int sum = root->val + lt.sum + rt.sum;
            ans = max(ans, sum);
            return Node(sum, min(root->val, lt.mini), max(root->val, rt.maxi));
        }
        return Node(max(lt.sum, rt.sum), INT_MIN, INT_MAX);
    }

    int maxSumBST(TreeNode* root) {
        ans = 0;
        helper(root);
        return ans;
    }
};