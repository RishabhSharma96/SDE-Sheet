class Solution{
    public:
    int solve(Node* root){
        
        if(!root){
            return 0;
        }
        
        if(!root->left && !root->right){
            return root->data;
        }
        
        int left = 0;
        if(root->left){
            left = solve(root->left);
        }
        
        int right = 0;
        if(root->right){
            right = solve(root->right);
        }
        
        if(root->data == left + right){
            return root->data;
        }
        return 1e8;
    }
    
    int isSumProperty(Node *root)
    {
        return solve(root)>=1e8 ? 0 : 1;
    }
};