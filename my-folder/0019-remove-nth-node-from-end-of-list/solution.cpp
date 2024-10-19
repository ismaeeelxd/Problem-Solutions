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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* curr = head;
        vector<ListNode*> arr;
        while(curr != nullptr){
            arr.push_back(curr);
            curr = curr->next;
        }
        if(arr.size() == 1){
            return nullptr;
        }
        int idx = arr.size() - n;
        if(idx == 0){
            return head->next;
        }
        arr[idx-1]->next = arr[idx]->next;
        return head;
    }
};
