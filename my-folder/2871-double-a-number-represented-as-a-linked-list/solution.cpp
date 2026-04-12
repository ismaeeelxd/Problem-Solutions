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
    int getUnits(int number) {
        return number % 10;
    }

    bool isNumberDoubleDigit(int number) {
        return number / 10;
    }


    bool solve(ListNode* head) {
        if(!head) return false;
        bool carryOne = solve(head->next);
        int num = head->val;
        int sum = carryOne ? num * 2 + 1 : num * 2;
        if(!isNumberDoubleDigit(sum)) {
            head->val = sum;
            return false;
        }
        int units = getUnits(sum);
        head->val = units;
        return true;
    }
    ListNode* doubleIt(ListNode* head) {
        bool isCarryOne = solve(head);
        if(isCarryOne) {
            ListNode* newNode = new ListNode(1, head);
            head = newNode;
        }

        return head;
    }
};
