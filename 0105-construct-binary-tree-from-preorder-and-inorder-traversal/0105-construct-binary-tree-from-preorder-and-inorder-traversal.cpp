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

int preidx = 0;

TreeNode* maketree(vector<int>& preorder,vector<int>& inorder,int l,int r)
{
    if(l>r)
    return NULL;

    TreeNode* root = new TreeNode(preorder[preidx++]);

    int idx;
    for(int i=l;i<=r;i++)
    {
        if(inorder[i]==root->val)
        {
            idx=i;
            break;
        }
    }

    root->left = maketree(preorder,inorder,l,idx-1);
    root->right= maketree(preorder,inorder,idx+1,r);
    return root;
}


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        if(preorder.size()==0)
        return NULL;

        // unordered_map<int,int> umap;
        // for(int i=0;i<inorder.size();i++)
        // {
        //     umap[inorder[i]]=i;
        // }

        TreeNode* root = maketree(preorder,inorder,0,inorder.size()-1);

        return root;
    }
};