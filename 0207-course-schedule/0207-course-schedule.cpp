class Solution {
public:

bool dfsrec(vector<bool>&visited, vector<bool>&recst,vector<int> adj[],int source)
{
    cout<<"source : " <<source<<endl;
    visited[source]=true;
    recst[source]=true;
    cout<<"recst["<<source<<"] : "<<recst[source]<<endl;

    for(auto u:adj[source])
    {
        cout<<"u: "<<u<<"   recst[" <<u<<"]: "<<recst[u]<<endl;
        if(visited[u]==false && dfsrec(visited,recst,adj,u))
        return true;
        
        else if(recst[u]==true)
        {
            cout<<"in else if: "<<endl;
        cout<<"u: "<<u<<"   recst["<< u<<"]: "<<recst[u]<<endl;
        return true;
        }
    }

    recst[source]=false;
    return false;

}


bool canFinish(int numcourses, vector<vector<int>>& prerequisites) 
{

    vector<int> adj[numcourses];

    for(int i=0;i<prerequisites.size();i++)
    {
        adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        //cout<<adj[prerequisites[i][1]][0]<<endl;
    }
    //theta(prerequisites) time

    // for(auto i:adj)
    // {
    //     for(auto u:i)
    //     cout<<u<<" ";
    //     cout<<endl;
    // }
    

    vector<bool> visited; //[numcourses];
    vector<bool> recst;//[numcourses];
    
    for(int i=0;i<numcourses;i++)
    {
    visited.push_back(false);
    recst.push_back(false);
    }   

    bool cycle =false;

    for(int i=0;i<numcourses;i++)
    {
        if(visited[i]==false)
        {
            if(dfsrec(visited,recst,adj,i)==true)
            {
            cycle= true;
            break;
            }
        }
    }

    if(cycle)return false;

    return true;


}



};