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
   int levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        if(!root)return 0;
        queue<TreeNode*> q;
        q.push(root);
        int x=0,y=0;
        
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
            x=vec.size();
            y+=x;
            x=0;
            v.push_back(vec);

        }


        return y;
        
}
        int lh(TreeNode* root)
        {
            TreeNode* curr = root;
           
            int h=0;
            while(curr!=NULL)
            {
                curr=curr->left;
                h++;
            }

            return h;
        }
        int rh(TreeNode* root)
        {
            TreeNode* curr = root;
            
            int h=0;
            while(curr !=NULL)
            {
                curr=curr->right;
                h++;
            }

            return h;
        }

        int countNodes(TreeNode* root) 
        {
            if(!root)return 0;

            int leftheight = lh(root);
            int rightheight = rh(root);

            if(leftheight==rightheight)
            {
               return (1<<leftheight) - 1;
            }

            else
            {
                return 1 + countNodes(root->left) + countNodes(root->right);
            }
        }

};