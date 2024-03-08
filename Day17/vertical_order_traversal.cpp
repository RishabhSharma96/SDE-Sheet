class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        
        vector<vector<int>> ans;
        
        if(!root){
            return ans;
        }
        
        queue<pair<TreeNode*, pair<int,int>>> q; // for -> {node, {horizontalLevel, verticalLevel}}
        map<int,map<int,multiset<int>>> mp ; // for -> mp[verticalLevel][horizontalLevel].insert(value);
        q.push({root, {0,0}});
        
        while(!q.empty()){
            
            auto it = q.front();
            q.pop();
            auto node = it.first;
            int horizontal = it.second.first;
            int vertical = it.second.second;
            
            mp[vertical][horizontal].insert(node->val) ;
            
            if(node->right){
                q.push({node->right, {horizontal+1, vertical+1}});
            }
            if(node->left){
                q.push({node->left, {horizontal+1, vertical-1}});
            }
        }
        
        for(auto it : mp){
            vector<int> temp ;
            for(auto itt : it.second){
                for(auto ittt : itt.second){
                    temp.push_back(ittt); 
                }
            }
            ans.push_back(temp);
        }
        
        return ans;
    }
};