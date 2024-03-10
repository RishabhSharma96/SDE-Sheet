class Solution {

private:
    void solve(Node* root){
        if(!root){
            return ;
        }

        if(root->left){
            root->left->next = root->right;
        } 
        if(root->next && root->right){
            root->right->next = root->next->left;
        } 

        solve(root->left);
        solve(root->right);
    }

public:
    Node* connect(Node* root) {
        solve(root);
        return root;
    }
};

// another approach is using Level order traversal