class Solution{
    public:
    
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key){
        
        pre = suc = NULL;
        
        Node* node = root;
        while(node){
            if(node->key <= key){
                node = node->right;
            } 
            else {
                suc = node;
                node = node->left;
            }
        }
        
        node = root;
        while(node){
            if(key > node->key){
                pre = node;
                node = node->right;
            } 
            else {
                node = node->left;
            }
        }
    }
};