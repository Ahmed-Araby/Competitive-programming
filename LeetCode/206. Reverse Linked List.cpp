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
    void shiftWindow(ListNode *&p, ListNode *&c, ListNode *&n)
    {
        p = c;
        c = n;
        if(c!=0){
            //listNode *p = c->next;
            n = c->next;
        }
        else 
            n = 0;
        return ;
    }
    
    ListNode* reverseList(ListNode* head) {
        
        if(head == 0 || head->next == 0)
            return head;
        
        // list has at least 3 nodes.
        ListNode * p = head;
        ListNode *c = head->next;
        ListNode *n = c->next;
        
        p->next  = 0;
        while(c!=0)
        {
            head = c;
            c->next = p;
            shiftWindow(p, c, n);
        }
        
        return head;
    }
};



// recursive
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

    ListNode * reverse(ListNode * head, ListNode *prev)
    {
        if(head ==0)
            return head;
        if(head->next == 0){
            head->next = prev;
            return head;
        }
        ListNode * newHead = reverse(head->next, head);
        head->next = prev;
        return newHead;
    }
    
    ListNode* reverseList(ListNode* head) {
        return reverse(head, 0);
    }
};
