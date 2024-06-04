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
    ListNode* rotateRight(ListNode* head, int k) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }

        ListNode* slow=head;
        ListNode* fast=head;

        int count=1;


        while(count<=k)
        {
            if(fast->next==NULL)
            fast=head;
            else
            fast=fast->next;

            count++;
        }    

if(fast==head)
return head;

        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next;
        }
        
        
            fast->next=head;
            head=slow->next;
            slow->next=NULL;
        
        return head;

    }
};