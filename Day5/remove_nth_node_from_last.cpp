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

    int countNodes(ListNode* head){
        int cnt=0 ;
        while(head){
            cnt++;
            head = head->next ;
        }
        return cnt;
    }

    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int totalNodes = countNodes(head);
        int nodeFromBeginning = totalNodes-n+1;

        if(nodeFromBeginning == 1){
            return head->next;
        }

        ListNode* temp = head;
        while(temp && nodeFromBeginning-2>0){
            head = head->next;
            nodeFromBeginning--;
        }

        head->next = head->next->next ? head->next->next : NULL ;

        return temp;

    }
};