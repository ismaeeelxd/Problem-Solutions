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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        if(!head) return nullptr;
        ListNode* head_ = head;
        ListNode* curNode = head;
        ListNode* prevNode = nullptr;
        unordered_set<int> nums_(nums.begin(),nums.end()); // for O(1) access
        while(curNode) {
            ListNode* nextNode = curNode->next;

            if(nums_.contains(curNode->val)) {
                // Must Remove
                if(prevNode) {
                    prevNode->next = nextNode;

                } else {
                    //Update global head
                    head_ = nextNode;
                }

                curNode = nextNode;
                continue;
            }

            prevNode = curNode;
            curNode = nextNode;
        }

        return head_;
    }
};
