/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:

    Node* createcopy(Node* head){

        // inserting new nodes
        Node* it = head;
        while(it != NULL){
            Node* newNode = new Node(it->val);
            Node* nextt = it->next;
            it->next = newNode;
            newNode->next = nextt;
            it = nextt;
        }

        // copying pointers
        it = head ;
        Node* tempIt = it->next;
        while(it!=NULL){
            if(it->random != NULL){
                tempIt->random = it->random->next;
            }
            it = tempIt->next;
            if(it){
                tempIt = it->next;
            }
        }

        // removing our nodes
        it = head;
        Node* ans = new Node(0);
        Node* ansHead = ans;
        tempIt = head->next;
        while(it != NULL){
            ans->next = tempIt;
            ans = ans->next;
            it->next = tempIt->next;
            it = it->next;
            if(it != NULL){
                tempIt->next = it->next;
                tempIt = tempIt->next;
            }
        }

        return ansHead->next;
    }

    Node* copyRandomList(Node* head) {
        if(!head){
            return NULL;
        }
        return createcopy(head);
    }
};