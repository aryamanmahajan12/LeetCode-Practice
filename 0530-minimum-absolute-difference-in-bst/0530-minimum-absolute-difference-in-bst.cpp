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
void inorder(TreeNode* root, vector<int>& v)
{
    if(root!=NULL)
    {
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
}
    int getMinimumDifference(TreeNode* root) 
    {
        vector<int> v;
        inorder(root,v);
        int min=INT_MAX;int dif=0;
        for(int i=1;i<v.size();i++)
        {
            dif=v[i]-v[i-1];
            if(dif<min)
            min=dif;
        }
        return min;
    }
};