// recursive
class Solution {
public:

    void solve(TreeNode* root, vector<int>& ans){
        if(root == NULL){
            return ;
        }
        solve(root->left,ans) ;
        ans.push_back(root->val) ;
        solve(root->right,ans) ;
    }

    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans ;
        solve(root,ans);
        return ans ;
    }
};


// iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,int>> s ; // for -> {node_To_Be_Pushed, to_Check_If_Left_Has_Been_Pushed_Or_Not=>{0 if not pushed 1 if pushed earlier}}
        vector<int> ans ;
        if(!root){
            return ans ;
        }

        s.push({root,0});

        while(!s.empty()){
            if((s.top().first -> left) && (s.top().second == 0)){
                s.top().second = 1 ;
                s.push({s.top().first -> left,0});
            }
            else{
                auto node = s.top().first ;
                s.pop() ;
                ans.push_back(node->val);

                if(node->right){
                    s.push({node->right,0});
                }
            }
        }
        return ans ;
    }
};