class Solution {
public:

    TreeNode* solve(vector<int> & nums, int start, int end){
        if(start > end){
            return NULL;
        }

        int mid = end - (end-start)/2;
        TreeNode* newNode = new TreeNode(nums[mid]);
        newNode->left = solve(nums, start, mid-1);
        newNode->right = solve(nums, mid+1, end);
        return newNode;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = nums.size() ;
        return solve(nums,0,n-1);
    }
};