class BSTIterator {
public:

    stack<TreeNode*> s;

    BSTIterator(TreeNode* root) {
        while(root){
            s.push(root);
            root = root->left;
        }
    }
    
    int next() {
        if(!s.empty()){
            auto node = s.top();
            int x = node->val;
            s.pop() ;   

            node = node->right;

            while(node){
                s.push(node);
                node = node->left;
            }
            return x;        
        }
        else{
            return -1;
        } 
    }
    
    bool hasNext() {
        return s.empty() ? false : true;
    }
};