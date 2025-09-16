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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return nullptr;
        ListNode* prev = head;
        ListNode* current = head->next;
        set<int> s;

        while(current != nullptr) {
            if(current->val == prev->val) s.insert(current->val);
            prev = current;
            current = current->next;
        }

        ListNode* currDummy = new ListNode(0);
        ListNode* curr = head;
        ListNode* newHead = currDummy; // ListNode0
        while(curr != nullptr) {
            if(!s.contains(curr->val)) {
                //Not duplicated
                currDummy->next = curr;
                currDummy = currDummy->next;
                curr = curr->next;
                currDummy->next = nullptr;
            } else {
                // Duplicated.
                curr = curr->next;
            }
        }

        return newHead->next;






    }
};
