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

    ListNode* getMid(ListNode* head){

        ListNode* slow = head;
        ListNode* fast = head;

        while(fast!=NULL){
            slow = slow->next;
            fast = fast->next;
            if(fast){
                fast = fast->next;
            }
        }
        return slow;
    }

    ListNode* reverseList(ListNode* head){
        ListNode* curr = head;
        ListNode* prev = NULL;
    
        while(curr!=NULL){
            ListNode* nextt = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nextt;
        }

        return prev;
    }

    bool isPalindrome(ListNode* head) {
        ListNode* mid = getMid(head);
        ListNode* reversedHead = reverseList(mid);
        
        while(head!=NULL && reversedHead!=NULL){
            if(head->val != reversedHead->val){
                return false;
            }
            head = head->next;
            reversedHead = reversedHead->next;
        }
        return true;
    }
};