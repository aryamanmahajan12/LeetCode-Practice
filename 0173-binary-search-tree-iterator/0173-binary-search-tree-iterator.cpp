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
class BSTIterator {
private:
vector<int> v;

void inorder(TreeNode* root, vector<int>& v)
{
    if(root!=NULL)
    {
        inorder(root->left,v);
        v.push_back(root->val);
        inorder(root->right,v);
    }
}
int i=-1;


public:


    BSTIterator(TreeNode* root) 
    {
     inorder(root,v);
    }
            
    int next() 
    {
        i++;
        return (v[i]);
    }
    
    bool hasNext() {
        if(i+1!=v.size())
        return true;

        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */