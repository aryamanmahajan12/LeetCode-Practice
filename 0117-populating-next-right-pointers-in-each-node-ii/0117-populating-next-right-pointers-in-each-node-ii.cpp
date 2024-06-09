/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:

    vector<vector<Node*>> levelOrder(Node* root) {
        vector<vector<Node*>> v;
        if(!root)return v;
        queue<Node*> q;
        q.push(root);
        
        Node* curr = root;
        
        while(!q.empty())
        {   
            int levelsize=q.size();
            curr=q.front();
            vector<Node*>vec;
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
              vec.push_back(curr);
              //cout<<curr->val<<" ";
              q.pop();levelsize--;
              curr=q.front();
            }

            v.push_back(vec);
        }


        return v;
    }


    Node* connect(Node* root) {

        vector<vector<Node*>> v = levelOrder(root);

        int s= v.size();
        for(int i=0;i<s;i++)
        {
            for(int j=0;j<v[i].size()-1;j++)
            {
                v[i][j]->next = v[i][j+1];
            }
        }

        return root;
    }
};