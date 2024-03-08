class Solution {
  public:
    void solve(Node* root){
        if(!root){
            return ;
        }   
        
        stack<Node*> s;
        s.push(root);
        
        while(!s.empty()){
            auto node = s.top();
            s.pop();
            
            Node* temp = node->left;
            node->left = node->right;
            node->right = temp ;
            
            if(node->right){
                s.push(node->right);
            }
            if(node->left){
                s.push(node->left);
            }
        }
    }
    
    void mirror(Node* node) {
        solve(node);
    }
};