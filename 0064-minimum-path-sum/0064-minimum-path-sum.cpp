class Solution 
{
public:

    int minPath(vector<vector<int>>& grid, int i, int j, map<pair<int,int>, int>& mp)
    {
        auto it = mp.find(make_pair(i,j));
        if(it!=mp.end()) return mp[make_pair(i,j)];
        int ans;
        if(i!=grid.size()-1 && j!= grid[0].size()-1)
        ans = min(grid[i][j] + minPath(grid,i+1,j,mp), grid[i][j]  + minPath(grid,i,j+1,mp));    
        if(i==grid.size()-1 && j!=grid[0].size()-1)
        ans = grid[i][j] + minPath(grid,i,j+1,mp);
        if(i!=grid.size()-1 && j==grid[0].size()-1)
        ans = grid[i][j] + minPath(grid,i+1,j,mp);
        if(i==grid.size()-1 && j==grid[0].size()-1)
        ans = grid[i][j];

        mp[make_pair(i,j)]=ans;
        return ans;
    }


    int minPathSum(vector<vector<int>>& grid) 
    {
        map<pair<int,int>, int> mp;
        int ans  = minPath(grid,0,0,mp);
        return ans;
    }
};