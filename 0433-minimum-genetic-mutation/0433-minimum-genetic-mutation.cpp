class Solution {
public:

int diffchar(string s1, string s2)
{
    int count=0;
    for(int i=0;i<s1.size();i++)
    {
        if(s1[i]!=s2[i])
        count++;
    }
    return count;
}

    int minMutation(string startGene, string endGene, vector<string>& bank) 
    {
        queue<string> q;
        string curr = startGene;
        q.push(curr);
        unordered_map<string,bool> umap;
        for(auto it:bank)
        umap[it]=false;

        int count=-1;
        while(!q.empty())
        {
            
            int levelsize=q.size();
            umap[curr]=true;
            count++;
            while(levelsize>0)
            {
                curr=q.front();
                if(curr==endGene)return count;
                q.pop();
                levelsize--;
                for(auto s :bank)
                {
                    if(diffchar(s,curr)==1 && umap[s]==false)
                    {
                        q.push(s);
                    }
                }

            }
        }

        return -1;

    }
};