class Solution 
{
public:

    int numPaths(vector<vector<int>>& grid,int i,int j,map<pair<int,int>,int>& mp)
    {
        if(grid[i][j]==1)return 0;

        auto it=mp.find(make_pair(i,j));
        if(it!=mp.end())
        return mp[make_pair(i,j)];

        int ans=0;

        if(i!=grid.size()-1 && j!=grid[0].size()-1 )
        {
            ans = numPaths(grid,i+1,j,mp) + numPaths(grid,i,j+1,mp);
        }
        if(i==grid.size()-1 && j!=grid[0].size()-1)
        {
            ans = numPaths(grid,i,j+1,mp);
        }
        if(i!=grid.size()-1 && j== grid[0].size()-1)
        {
            ans = numPaths(grid,i+1,j,mp);
        }
        if(i==grid.size()-1 && j== grid[0].size()-1 && grid[i][j]!=1)
        {
            ans = 1;
        }
        if(i==grid.size()-1 && j== grid[0].size()-1 && grid[i][j]==1)
        {
            ans = 0;
        }

        mp[make_pair(i,j)] = ans;
        return ans;         
    }

    int uniquePathsWithObstacles(vector<vector<int>>& grid) 
    {
        //if(grid[0][0]==1)return 0;
        map<pair<int,int>,int> mp;

        int ans = numPaths(grid,0,0,mp);
        return ans;
    }
};