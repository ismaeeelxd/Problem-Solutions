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
        if (!head || !(head->next))
            return head;
        ListNode* curr = head;
        ListNode* temp = head;
        while (curr != nullptr) {
            if (curr->val != temp->val) {
                temp->next = curr;
                temp = curr;
            }
            curr = curr->next;
        }
        temp->next = nullptr;
        return head;
    }
};
