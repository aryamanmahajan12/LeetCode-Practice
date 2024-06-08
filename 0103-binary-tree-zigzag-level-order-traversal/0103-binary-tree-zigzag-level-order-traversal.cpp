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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        
        vector<vector<int>> v;
        if(!root)return v;
        
        stack <TreeNode*> l2r;
        stack <TreeNode*> r2l;

        l2r.push(root);
        
        TreeNode* curr = root;
        int f=0;

        while( !( l2r.empty() && r2l.empty() ) )
        {   
            int levelsize;

            if(f==0)
            {
                curr=l2r.top();
                levelsize=l2r.size();
            }
            if(f==1)
            {
                curr=r2l.top();
                levelsize=r2l.size();
            }


            vector<int>vec;

            while(curr !=NULL  && levelsize>0)
            {
                if(f==0)
                {
                    if(curr->left!=NULL)
                    {
                    r2l.push(curr->left);
                    }
                    if(curr->right!=NULL)
                    {
                    r2l.push(curr->right);
                    }  
                    vec.push_back(curr->val);
                    cout<<curr->val<<" ";
                    l2r.pop();levelsize--;
                    if(!l2r.empty())
                    curr=l2r.top();
                    else
                    curr=NULL;
                }

                if(f==1)
                {
                    if(curr->right!=NULL)
                    {
                    l2r.push(curr->right);
                    }
                    if(curr->left!=NULL)
                    {
                    l2r.push(curr->left);
                    }  
                    vec.push_back(curr->val);
                    cout<<curr->val<<" ";
                    r2l.pop();levelsize--;
                    if(!r2l.empty())
                    curr=r2l.top();      
                    else
                    curr=NULL;             
                }

            }

            v.push_back(vec);
            if(f==0)f=1;
            else f=0;

            cout<<"f: "<<f<<endl;
        }


        return v;
    }
};