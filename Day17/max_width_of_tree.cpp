/**
* Definition for a binary tree node.
* struct TreeNode {
*     int val;
*     TreeNode *left;
*     TreeNode *right;
*     TreeNode() : val(0), left(nullptr), right(nullptr) {}
*     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
*     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
* };
*/

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {

        if(!root){
            return 0 ;
        }

        queue<pair<TreeNode*, long long>> q ;
        q.push({root,0});

        long long ans = 1 ;
        while(!q.empty()){
            long long size = q.size();
            long long start = -1, end = -1;
            long long minIndex = q.front().second;

            for(int i=0 ; i<size; i++){
                auto node = q.front();
                q.pop() ;
                auto nodeNum = node.second - minIndex;
                auto currNode = node.first;

                if(start == -1){
                    start = nodeNum;
                }
                else{
                    end = nodeNum;
                }

                if(currNode->left){
                    q.push({currNode->left, (long long)2*nodeNum+1});
                }
                if(currNode->right){
                    q.push({currNode->right, (long long)2*nodeNum+2});
                }
            }
            if(start != -1 && end != -1){
                ans = max(ans, end-start+1);
            }
        }
        return ans;
    }
};