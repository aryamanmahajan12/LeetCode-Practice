class Solution {
public:
int bfs(queue<int> q,  vector<vector<int>>&board,int n,bool visited[])//,unordered_map<int,pair<int,int>>umap)
{
    q.push(1);int count=-1;

    int x = 0;
    int y = board.size()-1;
    int m = board.size();
    int f=0;
    bool flag=false;
while(!q.empty())
{
    int levelsize=q.size();
    count++;
    while(levelsize>0)
    {
        int a = q.front();
        cout<<"a: "<<a<<endl;
        q.pop();
        levelsize--;
        if(a==(n))return count;
        int i;
            for(i=a+1;i<=min(a+6,n);i++)
            {
                if(i%m==0)
                {
                    y=i/m;
                    y=m-y;
                }
                else
                {
                    y=i/m;
                    y=m-1-y;
                }

                if(i%m==0)
                {
                    if(m%2!=0)
                    {
                        if(y%2==0)
                        x=m-1;
                        
                        else
                        x=0;
                    }

                    else
                    {
                        if(y%2!=0)
                        {
                            x=m-1;
                        }
                        else
                        {
                            x=0;
                        }
                    }
                }
                else
                {
                    if(m%2!=0)
                    {
                        if(y%2==0)
                        {
                        x=i%m-1;
                        }
                        else
                        {
                        x= (m) -  (i%m) ;
                        }
                    }
                    else
                    {
                        if(y%2!=0)
                        {
                            x = i%m -1;
                        }
                        else
                        {
                            x = m - (i%m);
                        }
                    }
                }
            cout<<"i: "<<i<<" ";
            cout<<"y: "<<y<<" x: "<<x<<" ";
            cout<<" board[y][x]: "<<board[y][x]<<endl;
            if(board[y][x] != -1 && !visited[i])
            {
            //flag=true;
            q.push(board[y][x]);
            visited[i]=true;
            }
            else if(!visited[i])
            {
            q.push(i);
            visited[i]=true;
            }
            }

            // if(!flag)
            // q.push(i);
            //flag=false;
        
    }
}

    return -1;
}



    int snakesAndLadders(vector<vector<int>>& board) 
    {
        int n = (board.size())*(board.size());
        
        unordered_map<int,pair<int,int>>umap;
        umap[0]= make_pair(0,0);int count=1;
        bool f=false;
        bool visited[n+1];

        for(int i=0;i<n+1;i++)
        visited[i]=false;



if(board[0][0]!=-1)return -1;


        // for(int i=board.size()-1;i>=0;i--)
        // {
        //     if(!f)
        //     {
        //     for(int j=0;j<board.size();j++)
        //     {
        //         umap[count]=make_pair(i,j);
        //         //cout<<count<<" "<<umap[count].first<<" "<<umap[count].second<<endl;
        //         count++;
        //     }
        //     f=!f;
        //     }
        //     else if(f)
        //     {
        //     for(int j=board.size()-1;j>=0;j--)
        //     {
        //         umap[count]=make_pair(i,j);
        //        // cout<<count<<" "<<umap[count].first<<" "<<umap[count].second<<endl;
        //         count++;
        //     }
        //     f=!f;                
        //     }
        // }

        queue<int> q;

        int  ans = bfs(q,board,n,visited);
        return ans;
       //return 0;
    }
};