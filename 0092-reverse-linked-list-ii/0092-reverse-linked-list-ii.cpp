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

ListNode* recrev(ListNode* head)
{
    if (head==NULL || head->next==NULL)
    return head;

    ListNode* resthead= recrev(head->next);
    ListNode* resttail= head->next;
    resttail->next = head;
    head->next=NULL;
    return resthead;
}



    ListNode* reverseBetween(ListNode* head, int left, int right) 
    {
        if(head==NULL ||left==right)
        return head;

        ListNode dummy(0);
        dummy.next=head;
        ListNode* prev = &dummy;

        int i=1;
        while(i<left)
        {
            prev=prev->next;
            i++;
        }

        
        ListNode* curr=prev->next;
        ListNode* temp=NULL;
        i=0;
        while(i<right-left)
        {
            temp=curr->next;
            curr->next=temp->next;
            temp->next=prev->next;
            prev->next=temp;
            ++i;
        }
        
        return dummy.next;

    }
};