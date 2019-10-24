/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

/*
* The priority queue is reversed in comparison. (min priority queue: > , max priority queue: <)
*
*/
struct SmallerValueNode
{
    int operator()(const ListNode * p1, const ListNode * p2)
    {
        return p1->val > p2->val;
    }
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, SmallerValueNode> pq;
        
        int k = lists.size();
        
        int i;
        for (i = 0; i < k; ++i)
        {
            if (lists[i]) 
            {
                pq.push(lists[i]);
            }
        }
        
        ListNode * head = NULL, * curNode = head;
        
        while (!pq.empty())
        {
            
            ListNode * tempNode = pq.top(); pq.pop();
            
            if (head == NULL)
            {
                head = new ListNode(tempNode->val);
                curNode = head;
            }
            else
            {
                curNode->next = new ListNode(tempNode->val);
                curNode = curNode->next;
            }
            
            tempNode = tempNode->next;
            
            if (tempNode)
            {
                pq.push(tempNode);
            }
        }
        return head;
    }
};
