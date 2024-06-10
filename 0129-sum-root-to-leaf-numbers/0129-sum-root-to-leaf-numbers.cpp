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
class Solution {
public:
    int sumNumbers(TreeNode* root) 
    {    
        if(root==NULL) return 0;

        stack<TreeNode*> node;
        stack<int> stk;
        TreeNode* curr=root;
        stk.push(curr->val);
        node.push(curr);
        int num=0;int sum=0;
        while(!node.empty())
        {
            curr=node.top();node.pop();
            num=stk.top();stk.pop();

            if(!curr->left && !curr->right)
            {
                sum+=num;
            }
            if(curr->left)
            {
                node.push(curr->left);
                stk.push(10*num + curr->left->val);
            }
            if(curr->right)
            {
                node.push(curr->right);
                stk.push(10*num + curr->right->val);
            }
        }
        return sum;
    }
};
