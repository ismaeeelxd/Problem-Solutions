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

function hasCycle(head: ListNode | null): boolean {
    if(!head) return false;
    let currPtr = head;
    let nextPtr = head.next;
    while(nextPtr){
        if(currPtr === nextPtr) return true;
        currPtr = currPtr.next;
        nextPtr = nextPtr.next != null ? nextPtr.next.next : null ;
    }

    return false;
};
