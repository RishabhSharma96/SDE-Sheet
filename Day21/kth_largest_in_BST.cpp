class Solution
{
    private:
        void solve(Node* root, int k, int& ans, int & currCount){
        if(!root){
            return;
        }

        solve(root->right, k, ans, currCount);
        currCount++;
        if(currCount == k){
            ans = root->data;
        }
        solve(root->left, k, ans, currCount);
    }
    
    public:
    int kthLargest(Node *root, int k)
    {
        int ans = 0, currCount = 0;
        solve(root,k,ans,currCount);
        return ans;
    }
};