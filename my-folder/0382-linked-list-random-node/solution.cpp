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

private: 
int min;
int max;
ListNode* head;
public:
    Solution(ListNode* head) {
        ListNode* current = head;
        this-> head = head;
        int size = 0;
        while(current) {
            current = current->next;
            size++;
        }
        this->min = 1;
        this->max = size;
        // cout << this->min << " " << this->max;

    }
    
    int getRandom() {
        if(!head) return -1;

        int random_num = std::rand() % (this->max - this->min + 1) + this->min;
        ListNode* current = head;
        for(int i = this->min; i < random_num ; ++i) {
            current = current->next;
        }
        cout << random_num << endl;
        return current->val;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(head);
 * int param_1 = obj->getRandom();
 */
