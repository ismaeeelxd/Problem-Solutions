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
    ListNode* kA2al(ListNode* head, ListNode* tail, int k, int length) {
        int index = 0;
        ListNode* cur = head;
        while (index < length - k - 1) {
            index++;
            cur = cur->next;
        }
        ListNode* newHead = cur->next;
        cur->next = nullptr;
        tail->next = head;
        return newHead;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head) return head;
        int length = 0;
        ListNode* he = head;
        ListNode* tail = NULL;
        while (he != nullptr) {
            if (he->next == nullptr)
                tail = he;
            he = he->next;
            length++;
        }
                    k = k % length;

        if (length == k || k == 0)
            return head;
        
            return kA2al(head, tail, k, length);

    }
};
