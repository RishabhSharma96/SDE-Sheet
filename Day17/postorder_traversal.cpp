// recursive
class Solution {
public:

    void solve(TreeNode* root, vector<int> &ans){
        if(!root){
            return ;
        }

        solve(root->left,ans);
        solve(root->right, ans);
        ans.push_back(root->val);

    }
    vector<int> postorderTraversal(TreeNode* root) {
                vector<int> ans;
        solve(root,ans);
        return ans;
    }
};


// iterative
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        stack<pair<TreeNode*,pair<int,int>>> s ; // for -> {pushed_node, {is_left_pushed, is_right_pushed}}
        vector<int> ans ;
        if(!root){
            return ans ;
        }

        s.push({root,{0,0}}) ;

        while(!s.empty()){
            if(s.top().first->left && s.top().second.first == 0){
                s.top().second.first = 1;
                s.push({s.top().first->left,{0,0}});
            }
            else{
                if(s.top().first->right && s.top().second.second == 0){
                    s.top().second.second = 1;
                    s.push({s.top().first->right,{0,0}}) ;
                }
                else{
                    auto node = s.top() ;
                    ans.push_back(node.first->val);
                    s.pop();
                }
            }
        }
        return ans ;
    }
};