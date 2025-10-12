/**
 * Definition for singly-linked list.
 * class ListNode {
 *     val: number
 *     next: ListNode | null
 *     constructor(val?: number, next?: ListNode | null) {
 *         this.val = (val===undefined ? 0 : val)
 *         this.next = (next===undefined ? null : next)
 *     }
 * }
 */

function mergeNodes(head: ListNode | null): ListNode | null {
    let prevZero = null;
    let curr = head.next;
    while(curr !== null) {
        let sum = 0;
        while(curr.val !== 0) {
            sum+=curr.val;
            curr = curr.next;
        }
        curr.val = sum;
        if(prevZero === null){
            prevZero = curr;
            head = prevZero;
        } 
        else{
            prevZero.next = curr;
            prevZero = curr;
        } 
        curr = curr.next;
    }
    return head;
};
