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
//int k=n-1;

TreeNode* maketree(int l,int r,vector<int>& inorder, vector<int>& postorder,int instart,int inend)
{
    if(r<l || inend<instart)
    return NULL;

    TreeNode* curr = new TreeNode(postorder[r]);

    int idx=0;int found=0;

    for(int i=instart;i<=inend;i++)
    {
        if(curr->val==inorder[i])
        {   
            found=1;
            idx=i;
            break;
        }
    }

        cout<<idx<<endl;
        
        curr->right =maketree(l+ idx - instart,r-1,inorder,postorder,idx+1,inend);
        curr->left  =maketree(l,l+idx-instart-1,inorder,postorder,instart,idx-1);

        return curr;
}


    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        if(postorder.size()==0)return NULL;

        TreeNode* root = maketree(0,postorder.size()-1,inorder,postorder,0,inorder.size()-1);
        return root;
    }
};