class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> ans;
        if(!root){
            return ans;
        }

        queue<TreeNode*> q;
        q.push(root);
        bool l2r = true;

        while(!q.empty()){
            int size = q.size() ;
            vector<int> helper(size) ;

            for(int i=0 ; i<size; i++){

                auto node = q.front();
                q.pop();

                helper[l2r ? i : size-i-1] = node->val;

                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }

            }
            l2r = !l2r ;
            ans.push_back(helper);
        }
        return ans;
    }
};