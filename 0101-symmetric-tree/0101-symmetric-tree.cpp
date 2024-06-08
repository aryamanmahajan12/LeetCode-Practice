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

    bool ismirror(TreeNode* a,TreeNode* b)
    {
    
    if(!a && !b)return true;

    else if(!a && b) return false;

    else if(!b && a) return false;

    else if(a && b)
    {
        if((a->val == b->val) && ismirror(a->left,b->right) && ismirror(a->right,b->left))
        {
            return true;
        }
        else
        return false;
    }
    else
    return false;

    }
    
    
bool isSymmetric(TreeNode* root) {
        
        bool a =ismirror(root->left,root->right);


        return a;


    }
};