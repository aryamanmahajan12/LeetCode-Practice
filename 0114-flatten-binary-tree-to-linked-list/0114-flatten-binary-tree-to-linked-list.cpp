/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution 
{
public:

void flatten(TreeNode* root) 
{
vector<TreeNode*> v;
    if(root!=NULL)
    {
        TreeNode* curr = root;
        stack<TreeNode*> stk;
        stk.push(curr);
        TreeNode* h;

        while(!stk.empty())
        {
            while(curr!=NULL)
            {
                v.push_back(curr);
                if(curr->right!=NULL)
                stk.push(curr->right);
                curr=curr->left;
            }
            curr=stk.top();stk.pop();            
        }

        for(int i=0;i<v.size()-1;i++)
        {
            v[i]->left=NULL;
            v[i]->right=v[i+1];    
        }
        
    }
    
}
};