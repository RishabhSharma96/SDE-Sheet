int findCeil(Node* root, int x) {

    int ans = INT_MAX;
        
    while(root){
        if(root->data == x){
            return x;
        }
        if(root->data >= x && root->data < ans){
            ans = root->data;
            root = root->left;
        }
        else{
            root = root->right;
        }
    }
    return ans==INT_MAX ? -1 : ans;
}

// ciel -> Ceil(X) is a number that is either equal to X or is immediately greater than X.