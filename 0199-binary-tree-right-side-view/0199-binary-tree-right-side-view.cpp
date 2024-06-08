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
    vector<int> rightSideView(TreeNode* root) 
    {
        vector<int> v;
        if(!root)return v;
        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* curr = root;
        
        while(!q.empty())
        {   
            int levelsize=q.size();
            curr=q.front();
            v.push_back(curr->val);
            while(curr !=NULL  && levelsize>0)
            {
              if(curr->right!=NULL)
              {
               q.push(curr->right);
              }
              if(curr->left!=NULL)
              {
               q.push(curr->left);
              }  
             //vec.push_back(curr->val);
              cout<<curr->val<<" ";
              q.pop();levelsize--;
              curr=q.front();
            }

            
        }


        return v;
    }
};