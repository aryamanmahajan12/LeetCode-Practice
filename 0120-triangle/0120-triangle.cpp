class Solution 
{
public:

int minPath(vector<vector<int>>& triangle, int i, int j, map<pair<int,int>,int>& mp)
{
    if(i==triangle.size()-1 ) return triangle[i][j];
    auto it = mp.find(make_pair(i,j));
    
    if(it!=mp.end()) return mp[make_pair(i,j)];

    int ans  = min(triangle[i][j] + minPath(triangle,i+1,j,mp), triangle[i][j] + minPath(triangle,i+1,j+1,mp));
    mp[make_pair(i,j)] = ans;

    return ans;

}   

    int minimumTotal(vector<vector<int>>& triangle) 
    {
        map<pair<int,int>, int> mp;

        int ans = minPath(triangle,0,0,mp);
        return ans;
    }


};