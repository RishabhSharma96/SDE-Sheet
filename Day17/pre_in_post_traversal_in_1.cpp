class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> pre, in, post;
        if(!root){
            return in;
        }

        stack<pair<TreeNode*, int>> s;
        s.push({root,0});
        
        while(!s.empty()){

            auto node = s.top();
            s.pop();

            if(node.second == 0){
                pre.push_back(node.first->val);
                s.push({node.first, node.second+1});
                if(node.first->left){
                    s.push({node.first->left, 0});
                }
            }
            else if(node.second == 1){
                in.push_back(node.first->val);
                s.push({node.first, node.second+1});
                if(node.first->right){
                    s.push({node.first->right, 0});
                }
            }
            else{
                post.push_back(node.first->val);
            }
        }

        for(auto it : pre){
            cout<<it<<" ";
        }cout<<endl;
        for(auto it : in){
            cout<<it<<" ";
        }cout<<endl;
        for(auto it : post){
            cout<<it<<" ";
        }cout<<endl;

        return in;
    }
};