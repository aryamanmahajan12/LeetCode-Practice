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



ListNode* getkth(ListNode* curr,int k)
{
    
    while(k>0 && curr!=NULL)
    {
        curr=curr->next;
        k--;
    }

    return curr;
}

    ListNode* reverseKGroup(ListNode* head, int k) 
    {
        if(head==NULL  || head->next==NULL || k==1)
        {
            return head;
        }

        //dealing with 2 or more nodes at least

        ListNode dummy(0,head);
        ListNode* grpprev= &dummy;
        ListNode* curr   = dummy.next;

        while(true)
        {
            ListNode*kth= getkth(grpprev,k);

            if(kth==NULL)
            {
                break;
            }

            ListNode* grpnext= kth->next;
            
            ListNode* prev   = grpnext;      //classic move
            curr             = grpprev->next;

            while(curr!=grpnext)
            {
                ListNode* temp = curr->next;
                curr->next = prev;
                prev=curr;
                curr=temp;
            }

           ListNode* t =grpprev->next;
           grpprev->next=kth;
           grpprev=t;
        }

return dummy.next;







        // ListNode*prev=&dummy;
        // ListNode*prevgrp=prev;
        // ListNode*curr=prev->next;
        // int count=1;


        // if(count<k)
        // return head;

        // ListNode* kth=curr;//1st is next of prev
        // ListNode* nextgrp=curr->next;

        // curr=prev->next;
        // while(curr!=nextgrp)
        // {
        //     ListNode* temp=curr->next;
        //     curr->next=prev;
        //     prev=curr;
        //     curr=temp;
        // }

        // prevgrp->next = prev;
        // prev->next = nextgrp;

        





    }
};