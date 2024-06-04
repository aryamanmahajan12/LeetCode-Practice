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
    ListNode* deleteDuplicates(ListNode* head) 
    {
        if(head==NULL || head->next==NULL)
        {
            return head;
        }    
        
        ListNode* p   =head;
        ListNode* prev=head->next;
        ListNode* curr=head->next->next;
        int flag=0;int f=0;
        ListNode* pdot=head;

        while(curr!=NULL)
        {               
                while(curr!=NULL && prev->val==curr->val )
                {
                    flag=1;
                    curr=curr->next;
                }

            if(flag==1)
            {
                if(p->val==prev->val)
                {
                    p=curr; 
                }
                else
                {
                    p->next=curr;
                    if(f!=1)
                    {
                    head=p;
                    f=1;
                    }
                }
                
                flag=0;
            }
            else
            {
                if(p->val==prev->val)
                {
                    p=curr;   
                }     
                else
                {
                    if(f!=1)
                    {
                    head=p;
                    f=1;
                    } 
                    p=prev;
                }      
                    
            }

            if(p!=NULL)
            prev=p->next;
            else
            prev=NULL;

            if(prev!=NULL)
            curr=prev->next;
            else
            curr=prev;
        }
        // if(f)
        // return head;

if(f!=1)
{
                    if(prev!=NULL)
                    {
                                if(p->val==prev->val)
                                {
                                    head=curr;
                                }
                                else
                                {
                                    head=p;
                                }
                    }    
                    else
                    head=p;  
}



        
    return head;
    }
    
};