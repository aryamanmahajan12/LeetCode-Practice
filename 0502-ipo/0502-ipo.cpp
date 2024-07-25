class Solution 
{
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) 
    {
        priority_queue<int> mxhp;
        
        vector<pair<int,int>> vec;
        
        for(int i=0;i<capital.size();i++)
        {
            vec.push_back(make_pair(capital[i],profits[i]));
        }

        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> mnhp(vec.begin(),vec.end());


        for(int i=1;i<=k;i++)
        {
            while(!mnhp.empty() && mnhp.top().first <= w)
            {
                auto it = mnhp.top();
                mxhp.push(it.second);
                mnhp.pop();
            }

            if(mxhp.empty())break;

            w += mxhp.top();
            mxhp.pop();
        }

        return w;
    }
};
