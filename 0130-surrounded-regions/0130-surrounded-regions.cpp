class Solution {
public:

void dfsrec(vector<vector<char>>& board, vector<vector<bool>>& visited, int s1, int s2,vector<pair<int,int>>& v)
{
    visited[s1][s2]=true;
    v.push_back(make_pair(s1,s2));

    if(s1+1<board.size())
    {
        if(visited[s1+1][s2]==false && board[s1+1][s2]=='O')
        dfsrec(board,visited,s1+1,s2,v);
    }
    if(s2+1<board[0].size())
    {
        if(visited[s1][s2+1]==false && board[s1][s2+1]=='O')
        dfsrec(board,visited,s1,s2+1,v);
    }
    if(s1-1>=0)
    {
        if(visited[s1-1][s2]==false && board[s1-1][s2]=='O')
        dfsrec(board,visited,s1-1,s2,v);
    }
    if(s2-1>=0)
    {
        if(visited[s1][s2-1]==false && board[s1][s2-1]=='O')
        dfsrec(board,visited,s1,s2-1,v);
    }


}

    void solve(vector<vector<char>>& board) 
    {
        vector<bool> vec;
        vector<vector<bool>>visited;

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                vec.push_back(false);
            }
            visited.push_back(vec);
            vec.clear();
        }
        
        vector<pair<int,int>>v;bool flag=false;

        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]=='O' && visited[i][j]==false)
                {
                    dfsrec(board,visited,i,j,v);
                    flag=false;
                    for(auto item:v)
                    {
                        if(item.first==0 || item.first==board.size()-1 || item.second==0 || item.second==board[0].size()-1)
                        {
                            flag =true;
                            break;
                        }
                    }
                    if(flag==false)
                    {
                        for(auto item:v)
                        {
                            board[item.first][item.second]='X';
                        }
                    }
                    v.clear();
                }
            }
        }


    }
};