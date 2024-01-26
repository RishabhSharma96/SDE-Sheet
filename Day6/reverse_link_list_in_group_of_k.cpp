/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* reverseList(ListNode* head, int k){

        ListNode* it = head;
        int numIt = k-1 ;
        while(numIt--){
            if(it->next){
                it = it->next;
            }
            else{
                return head;
            }
        }

        numIt = k;

        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nextt = curr->next;

        while(curr!=NULL && numIt>0){
            nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
            numIt--;
        }

        if(curr){
            ListNode* front = reverseList(curr,k);
            head->next = front;
        }
        return prev;

    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        return reverseList(head,k);
    }
};