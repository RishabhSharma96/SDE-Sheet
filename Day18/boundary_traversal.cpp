class Solution {
    
private:
    void left(Node* root, vector<int> & ans){
        if(!root->left){
            ans.push_back(root->data);
            return;
        }
        Node* curr = root; 
        
        while(curr->left || curr->right){
            if(!curr->left && !curr->right){
                break;
            }
            
            if(curr->left){
                ans.push_back(curr->data);
                curr = curr->left;
            }
            else{
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
    
    void leaves(Node* root, vector<int> & ans){
        if(!root){
            return ;
        }
        
        leaves(root->left, ans);
        if(!root->left && !root->right){
            ans.push_back(root->data);
        }
        leaves(root->right, ans);
    }
    
    void right(Node* root, vector<int> & ans){
        if(!root->right){
            return;
        }
        Node* curr = root; 
        vector<int> temp ;
        
        while(curr->left || curr->right){
            if(!curr->left && !curr->right){
                break;
            }
            
            if(curr->right){
                temp.push_back(curr->data);
                curr = curr->right;
            }
            else{
                temp.push_back(curr->data);
                curr = curr->left;
            }
        }
        
        for(int i=0 ; i<temp.size()-1; i++){
            ans.push_back(temp[temp.size()-1-i]);
        }
    }
    
public:
    vector <int> boundary(Node *root)
    {
        vector<int> ans ;
        if(!root){
            return ans;
        }
        if(!root->left && !root->right){
            ans.push_back(root->data);
            return ans;
        }
        left(root, ans);
        leaves(root,ans);
        right(root,ans);
        return ans;
    }
};
