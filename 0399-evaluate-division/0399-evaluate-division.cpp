class Solution 
{
public:

double bfs(string x, unordered_map<string,vector<pair<string,double>>> umap,  unordered_map<string,bool>& visited,string target)
{
    queue<pair<string,double>> q;
    string curr=x;

    for(auto item: umap[curr])
    {
        if(item.first==target)
        {
            return item.second;
        }
        q.push(item);
        visited[item.first]=true;
    }

    while(!q.empty())
    {
        auto curr=q.front();
        visited[curr.first]=true;
        q.pop();

        for(auto it=umap[curr.first].begin();it!=umap[curr.first].end();it++)
        {
           if(!visited[it->first])  
           {
           it->second = it->second*curr.second;
           q.push(*it);
           visited[it->first]=true;
           if(it->first==target)        
           return it->second;
           }
        }
    }

    return -1.0;
}

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map< string, vector < pair < string,double > > > umap;

        for(int i=0;i<equations.size();i++)
        {
            umap[equations[i][0]].push_back(make_pair(equations[i][1],values[i]));
            umap[equations[i][1]].push_back(make_pair(equations[i][0],1/values[i]));
        }
        double val=1.0;
        
        vector<double>ans;
        for(auto item:queries)
        {   
            unordered_map<string,bool>visited;
            if(item[0]==item[1])
            {
                if( !(umap[item[0]].empty()) )
                ans.push_back(1.0);
                else
                ans.push_back(-1.0);
            }
            else
            {
            if( !(umap[item[0]].empty()) )
            {
                val=bfs(item[0],umap,visited,item[1]);
                if(val==-1.0)
                {   
                    unordered_map<string,bool> kvisited;
                    if(!(umap[item[1]].empty()))
                    {
                        val=bfs(item[1],umap,kvisited,item[0]);
                        if(val!=-1.0)val=1/val;
                    }
                }

                ans.push_back(val);
            }
            else if(!(umap[item[1]].empty()) )
            {
                val= bfs(item[1],umap,visited,item[0]);
                val=1/val;
                ans.push_back(val);
            }
            else
            {
                val=-1.0;
                ans.push_back(val);
            }
            }
        }
        return ans;
    }
};