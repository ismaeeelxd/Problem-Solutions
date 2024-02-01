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
    int getDecimalValue(ListNode* head) {
        if(!head){
            return 0;
        }
        else {
                stack<int> numbers;
                ListNode *current = head;
                while(current){
                    numbers.push(current->val);
                    current = current->next;
                }
                int number = 0;
                                    int i = 0;

                while(!numbers.empty()){
                        number+=(pow(2,i) * numbers.top());
                        numbers.pop();
                        ++i;

                }
                        
                    
                    
                

                return number;



        }

    }
};
