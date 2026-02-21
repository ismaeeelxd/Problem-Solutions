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
    ListNode *detectCycle(ListNode *head) {
        map<ListNode*, int> s;
        ListNode* cur = head;
        int index = 0;
        int pos = -1;
        while(cur) {
            if(s.contains(cur)) {
                pos = s[cur];
                return cur;
            }
            s[cur] = index;
            index++;
            cur = cur->next;
        }

        return NULL;
    }
};
