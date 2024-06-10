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
int maxn(TreeNode* root)
{
    if(root==NULL)
    return INT_MIN;

    return max(root->val, max(maxn(root->left),maxn(root->right)));

}
int minn(TreeNode* root)
{
    if(root==NULL)
    return INT_MAX;

    return min(root->val, min(minn(root->left), minn(root->right)));
}
void inorder(TreeNode* root, vector<int>& v)
{
    if(root!=NULL)
    {
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
}
    bool isValidBST(TreeNode* root) 
    {
        vector<int> v;
        inorder(root,v);
        for(int i=1;i<v.size();i++)
        {
            if(v[i]<=v[i-1])
            return false;
        }
        return true;
    }
};