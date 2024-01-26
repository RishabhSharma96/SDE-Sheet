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

    ListNode* addTwoNumbers(ListNode* list1, ListNode* list2) {
        
        if(!list1){
            return list2;
        }
        if(!list2){
            return list1;
        }

        ListNode* ans = new ListNode(-1);
        ListNode* ansHead = ans;
        int carry = 0;

        while(list1 || list2){

            int num1 = 0 ; 
            if(list1){
                num1 = list1->val;
                list1 = list1->next;
            }

            int num2 = 0 ; 
            if(list2){
                num2 = list2->val;
                list2 = list2->next;
            }

            int num = (num1 + num2 + carry);
            int digit = num%10 ;
            carry = num/10 ;

            ListNode* temp = new ListNode(digit);
            ans->next = temp;
            ans = temp;
        }

        if(carry > 0){
            ListNode* temp = new ListNode(carry);
            ans->next = temp;
        }

        return ansHead->next;
    }
};