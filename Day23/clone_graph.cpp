class Solution {
public:

    Node* clone(Node* node, unordered_map<Node*, Node*> & mapping){
        if(mapping.find(node) != mapping.end()){
            return mapping[node];
        }

        Node* newNode = new Node(node->val);
        mapping[node] = newNode;
        
        for(auto it : node->neighbors){
            newNode->neighbors.push_back(clone(it, mapping));
        }
        return newNode;
    }

    Node* cloneGraph(Node* node) {
        if(!node){
            return node;
        }
        unordered_map<Node*, Node*> mapping ; // old to new node mapping
        return clone(node, mapping);
    }
};