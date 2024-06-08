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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)return v;
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* curr = root;
        
        while(!q.empty())
        {   
            int levelsize=q.size();
            curr=q.front();
            vector<int>vec;
            while(curr !=NULL  && levelsize>0)
            {
              if(curr->left!=NULL)
              {
               q.push(curr->left);
              }
              if(curr->right!=NULL)
              {
               q.push(curr->right);
              }  
              vec.push_back(curr->val);
              cout<<curr->val<<" ";
              q.pop();levelsize--;
              curr=q.front();
            }

            v.push_back(vec);
        }


        return v;
    }
};