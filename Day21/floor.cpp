class Solution{

public:
    int floor(Node* root, int x) {
        int ans = INT_MIN;
        
        while(root){
            if(root->data <= x && root->data > ans){
                ans = root->data;
                root = root->right;
            }
            else{
                root = root->left;
            }
        }
        return ans==INT_MIN ? -1 : ans;
    }
};

// floor -> greatest value node of the BST which is smaller than or equal to ‘X’