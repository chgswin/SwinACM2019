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
    
    ListNode * reverseWithBothEnd(ListNode * head, ListNode * tail)
    {
        if (head == NULL) return NULL;
        if (head == tail) return head;
        
        ListNode * previous = head;
        ListNode * current = head->next;
        
        while (previous != tail && current)
        {
            ListNode * next = current-> next;
            current->next = previous;
            previous = current;
            current = next;
        }
               
        if (tail) return tail;
        else return previous;
        
    }
    
    ListNode * getNextKNode(ListNode * head, int k)
    {
        while (k-- && head)
        {
            head = head->next;
        }
        return head;
    }
    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        ListNode * globalHead = NULL;
        
        ListNode * curhead = head;
        ListNode * lastTail = NULL;
        ListNode * curtail;
        if (!getNextKNode(head, k-1)) return head;
        
        while (curtail = getNextKNode(curhead, k-1))
        {
            ListNode * nexthead = curtail->next;
               
            ListNode * newTail = curhead;
            
            ListNode * newHead = reverseWithBothEnd(curhead, curtail);
            if (!globalHead) globalHead = newHead;
            
            newTail->next = nexthead;
            
            curhead = nexthead;
            if (lastTail) lastTail->next = newHead;
            lastTail = newTail;
        }
        
       return globalHead;
    }
};
