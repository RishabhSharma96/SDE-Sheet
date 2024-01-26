/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:

    int getLen(ListNode *head){
        int cnt=0 ;
        while(head){
            cnt++;
            head = head->next;
        }
        return cnt;
    }

    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len1 = getLen(headA);
        int len2 = getLen(headB);

        int lenDiff = abs(len1 - len2);

        if(len1>len2){
            while(lenDiff--){
                headA = headA->next;
            }
        }
        else{
            while(lenDiff--){
                headB = headB->next;
            }
        }

        while(headA != headB){
            headA = headA->next;
            headB = headB->next;
        }

        return headA;
    }
};