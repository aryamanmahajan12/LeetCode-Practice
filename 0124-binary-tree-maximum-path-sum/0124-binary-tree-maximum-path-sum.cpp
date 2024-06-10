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
int maxima = INT_MIN;
    int helper(TreeNode* root)
    {
        if(!root)return 0;
        
        int leftmax = helper(root->left);
        int rightmax= helper(root->right);
        leftmax = max(leftmax,0);
        rightmax= max(rightmax,0);

        maxima = max(maxima,root->val+leftmax+rightmax);

        return root->val + max(leftmax,rightmax);

    }


    int maxPathSum(TreeNode* root) 
    {

        if(root==NULL)
        return 0;

        int ans = helper(root);
        
        return maxima;
        
    }
};