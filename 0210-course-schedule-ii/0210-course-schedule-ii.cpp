class Solution {
public:



bool dfsrec(stack<int>&stk,bool visited[],bool recst[],vector<int> adj[],int source)
{
    cout<<"source : " <<source<<endl;
    visited[source]=true;
    recst[source]=true;
    cout<<"recst["<<source<<"] : "<<recst[source]<<endl;

    for(auto u:adj[source])
    {
        cout<<"u: "<<u<<"   recst[" <<u<<"]: "<<recst[u]<<endl;
        if(visited[u]==false && dfsrec(stk,visited,recst,adj,u))
        return true;
        
        else if(recst[u]==true)
        {
        cout<<"in else if: "<<endl;
        cout<<"u: "<<u<<"   recst["<< u<<"]: "<<recst[u]<<endl;
        return true;
        }
    }

    recst[source]=false;
    stk.push(source);
    return false;

}

    vector<int> findOrder(int numcourses, vector<vector<int>>& prerequisites) 
    {
        vector<int> adj[numcourses];

        for(int i=0;i<prerequisites.size();i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }        

        bool visited[numcourses];
        bool recst[numcourses];

        for(int i=0;i<numcourses;i++)
        {
            visited[i]=false;
            recst[i]=false;
        }

        bool cycle=false;
        stack<int>stk;

        for(int i=0;i<numcourses;i++)
        {
            if(!visited[i])
            {
                if(dfsrec(stk,visited,recst,adj,i)==true)
                {
                    cycle=true;
                    break;
                }
            }
        }

        vector<int>ans;
        if(cycle)return ans; 

        else
        {
            while(!stk.empty())
            {
                ans.push_back(stk.top());
                stk.pop();
            }
            return ans;
        }
    }
};