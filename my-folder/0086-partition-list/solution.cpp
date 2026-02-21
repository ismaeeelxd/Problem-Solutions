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
    ListNode* partition(ListNode* head, int x) {
        if(!head) return head;
        ListNode* stickToNext = new ListNode(INT_MIN, head);
        ListNode* dummy = stickToNext;
        ListNode* nextToStick = head;
        while(stickToNext && stickToNext->next && stickToNext->next->val < x) stickToNext = stickToNext->next; // 1 
        if(stickToNext->next) nextToStick = stickToNext->next; // 4
        else return head;
        ListNode* prev = stickToNext; // 1
        ListNode* cur = nextToStick; // 4

        while(cur) {
            if(cur->val < x) {
                // MUST MOVE  
                prev->next = cur->next; // 3 -> 2
                ListNode* next = stickToNext-> next; // 4
                stickToNext->next = cur; // 1 -> 0
                stickToNext = cur;
                cur->next = next; // 
                cur = prev->next; // 
            } else {
                prev = cur; // 3
                cur = cur->next; // 0
            }

        }
        return dummy->next;
    }                            
};
