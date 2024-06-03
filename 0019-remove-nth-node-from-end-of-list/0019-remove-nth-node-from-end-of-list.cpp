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
    ListNode* removeNthFromEnd(ListNode* head, int n) 
    {
        if(head==NULL)
        return head;

        if(head->next==NULL)
        {
            return NULL;
        }

        ListNode* slow= head;
        ListNode* slower = head;
        ListNode* fast= head;

        int count=1;

        while(count<=n)
        {
            fast=fast->next;
            count++;
        }
        
    if(fast!=NULL)
    {   slow  =slow->next;
        fast=fast->next;
    }
        while(fast!=NULL)
        {
            slow=slow->next;
            slower=slower->next;
            fast=fast->next;
        }
       
       ListNode* temp = slow->next;

        slower->next=temp;

        if(slow==head)
        {
            head=slow->next;
        }
        
        delete(slow);
       
        return head;
    }
};