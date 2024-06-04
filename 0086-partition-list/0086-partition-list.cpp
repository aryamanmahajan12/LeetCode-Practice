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
    ListNode* partition(ListNode* head, int x) {

        if(head==NULL || head->next==NULL)
        return head;

        
        ListNode* l1head = new ListNode(0);
        ListNode* l2head = new ListNode(0);
        ListNode* l1tail =l1head;
        ListNode* l2tail =l2head;

        ListNode* p = head;

        while(p!=NULL)
        {
            if(p->val<x)
            {
                ListNode* temp = new ListNode(p->val);
                l1tail->next=temp;
                l1tail=temp;
            }
            else
            {
                ListNode* temp = new ListNode(p->val);
                l2tail->next=temp;
                l2tail=temp;                
            }
            p=p->next;
        }

        if(l1head==l1tail)
        {
            return l2head->next;
        }
        if(l2head==l2tail)
        {
            return l1head->next;
        }

        l1head=l1head->next;
        l2head=l2head->next;
        l1tail->next=l2head;

        return l1head;
    }
};