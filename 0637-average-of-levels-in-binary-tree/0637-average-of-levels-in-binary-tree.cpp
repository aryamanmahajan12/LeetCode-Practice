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
    vector<double> averageOfLevels(TreeNode* root) 
    {
        vector<double> v;
        if(!root)return v;

        queue<TreeNode*> q;
        q.push(root);
        
        TreeNode* curr = root;
        
        while(!q.empty())
        {   
            int levelsize=q.size();
            curr=q.front();
            double req = levelsize;
            double avg=0;

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
              
              //cout<<curr->val<<" ";

              avg += curr->val;
              q.pop();levelsize--;
              curr=q.front();

            }

            v.push_back((avg/req));
        }


        return v;
    }
};