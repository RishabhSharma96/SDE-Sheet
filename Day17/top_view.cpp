class Solution {
public:
    vector <int> topView(Node *root) {
        vector<int> ans;
        
        if(!root){
            return ans;
        }
        
        queue<pair<Node*, int>> s; // for -> {node, level_at_which_the_node_is_present}
        map<int,int> mp ; // to map -> level to nodeValue
        s.push({root, 0});
        
        while(!s.empty()){
            
            auto it = s.front();
            s.pop();
            auto node = it.first;
            int level = it.second;
            
            if(mp.find(level) == mp.end()){
                mp[level] = node->data ;
            }
            
            
            if(node->left){
                s.push({node->left, level-1});
            }
            if(node->right){
                s.push({node->right, level+1});
            }
        }
        
        for(auto it : mp){
            ans.push_back(it.second);
        }
        
        return ans;
    }
};