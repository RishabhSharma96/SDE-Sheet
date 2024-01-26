// iterative
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        if(!head || !head->next) return head ;

        ListNode* curr = head ;
        ListNode* prev = nullptr;

        while(curr != nullptr){
            ListNode* nextt = curr->next;
            curr->next = prev ;
            prev = curr ;
            curr = nextt ;
        }
        return prev ;

    }
};

// recursive
class Solution {
public:

    ListNode* reverse(ListNode* head){
        if(!head || !head->next){
            return head;
        }

        ListNode* reversedList = reverse(head->next);
        ListNode* front = head->next;
        front->next = head;
        head->next = NULL;
        return reversedList;
    }

    ListNode* reverseList(ListNode* head) {
        return reverse(head);
    }
};