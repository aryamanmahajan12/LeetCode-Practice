/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:

void dfs(Node* node,  unordered_map<Node*,Node*>& umap, Node* parent)
{
    cout<<node->val<<endl;
    if(umap[node]==NULL)
    {
    Node* n = new Node(node->val); 
    umap[node]=n;
    umap[parent]->neighbors.push_back(n);
    }
    else
    {
        umap[parent]->neighbors.push_back(umap[node]);
    }
   

    for(auto it : node->neighbors)
    {
        if(umap[it]==NULL)
        dfs(it,umap,node);

        else
        {
            umap[node]->neighbors.push_back(umap[it]);
        }
    }


}


Node* cloneGraph(Node* node) 
{

    if(node==NULL)return node;
    
    unordered_map<Node*, Node*> umap;
    
    Node* n = new Node(node->val);

    umap[node]=n;

    for(auto it :node->neighbors)
    {
        if(umap[it]==NULL)
        dfs(it,umap,node);
        else
        umap[node]->neighbors.push_back(umap[it]);
    }

    return n;

}
};