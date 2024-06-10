/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
bool contains(TreeNode* root,TreeNode* p)
{
    if(root==p)
    return true;
    if(root==NULL)
    return false;

    if(contains(root->right,p) || contains(root->left,p))
    {
        return true;
    }

    else
    return false;
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) 
    {
        if(root==p )return p;
        if(root==q )return q;

        if((contains(root->left,p) && contains(root->right,q)) || (contains(root->left,q) && contains(root->right,p)))
        {
            return root;
        }
        if( (root==p && (contains(root->left,q) || contains(root->right,q))) || ( root==q && (contains(root->left,p) || contains(root->right,p)) ))
        {
            return root;
        }
        if( (contains(root->left,q) && contains(root->left,p)) ) 
        {
            return lowestCommonAncestor(root->left,p,q);
        }
        if(contains(root->right,p) && contains(root->right,p))
        {
            return lowestCommonAncestor(root->right,p,q);
        }
        else
        return NULL;



    }
};