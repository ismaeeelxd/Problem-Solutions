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
    void reorderList(ListNode* head) {
        ListNode* tail = head;
        
        int length = 0;

        // 1 -> 2 > 3 > 4
        while(tail->next) {
            tail = tail->next;
            length++;
        }

        int to = length / 2; // 1
        ListNode* cur = head;
        ListNode* prev = nullptr;

        int i = 0;

        while(cur) {
            if(i < to){
                prev = cur;
                cur = cur->next;
                ++i;
                continue;
            }
            ListNode* next = cur->next;

            if(i == to) {
                prev = cur;
                cur->next = nullptr;
                cur = next;
                ++i;
                continue;
            }
            if(i == to + 1) {
                prev = cur;
                cur->next = nullptr;
                cur = next;
                ++i;
                continue;
            }
            cur->next = prev;
            prev = cur;
            cur = next;
        }

        ListNode* hptr = head;
        ListNode* tptr = tail;
        while(hptr && tptr) {
            ListNode* hnext = hptr->next;
            ListNode* tnext = tptr->next;
        
                hptr->next = tptr;
                tptr->next = hnext;
                hptr = hnext;
                tptr = tnext;
        }
    }
};
