class Solution {
public:

void dfsrec(vector<vector<char>>& grid, vector<vector<bool>>&visited, int s1,int s2)
{

    visited[s1][s2]=true;  
    cout<<s1<<" "<<s2<<endl;
    
        if(s1+1<grid.size())
        {
            if(visited[s1+1][s2]==false && grid[s1+1][s2]=='1')
            {
                dfsrec(grid,visited,s1+1,s2);
            }
        }

        if(s2+1<grid[0].size())
        {
            if(visited[s1][s2+1]==false && grid[s1][s2+1]=='1')
            {
                dfsrec(grid,visited,s1,s2+1);
            }
        }

        if(s1-1>=0)
        {
            if(visited[s1-1][s2]==false && grid[s1-1][s2]=='1')
            {
                dfsrec(grid,visited,s1-1,s2);
            }
        }
        
        if(s2-1>=0)
        {
            if(visited[s1][s2-1]==false && grid[s1][s2-1]=='1')
            {
                dfsrec(grid,visited,s1,s2-1);
            }
        }
    

}

int dfs(vector<vector<char>>& grid,vector<vector<bool>>& visited)
{
    int count=0;
    for(int i=0;i<grid.size();i++)
    {
        for(int j=0;j<grid[i].size();j++)
        {
            if(visited[i][j]==false && grid[i][j]=='1')
            {
                cout<<count<<"th call "<<endl;
                dfsrec(grid,visited,i,j);
                count++;
            }
        }
    }
    return count;
}



    int numIslands(vector<vector<char>>& grid) 
    {
        
        vector<vector<bool>> visited;
        vector<bool> vec;
        for(int j=0;j<grid.size();j++)
        {
            for(int k=0;k<grid[j].size();k++)
            {
            vec.push_back(false);
            }
            visited.push_back(vec);
            vec.clear();
        }

        int ans = dfs(grid,visited);

        return ans;
    }
};