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

    int countNodes(ListNode * head){
        auto temp=head;
        int cnt=0;
        while(temp!=NULL){
            cnt++;
            temp=temp->next;
        }
        return cnt;
    }

    ListNode* rotateRight(ListNode* head, int k) {

        if(!head || !head->next || k==0){
            return head;
        }
        
        ListNode* temp = head;
        int n = countNodes(head);

        while(temp->next != NULL){
            temp = temp->next;
        }

        temp->next = head;
        k = k%n;
        int cntr = n-k;

        while(cntr>1){
            head = head->next;
            cntr--;
        }

        ListNode* ans = head->next;
        head->next = NULL;
        return ans;
    }
};