class Solution 
{
public:

bool f(int idx, set<string>& st, vector<int>& dp,string s)
{
    if(idx==s.size())return true;
    string temp;
    if(dp[idx]!=-1)
    return dp[idx];

    for(int i=idx;i<s.size();i++)
    {
        temp+=s[i];
        if(st.find(temp)!=st.end())
        {
            if(f(i+1,st,dp,s))
            return dp[idx]=true;
        }
    }

    return dp[idx]=false;
}




bool wordBreak(string s, vector<string>& wordDict) 
{
    set<string> st;
    for(auto w : wordDict)
    {
        st.insert(w);
    }

    int n = s.length();
    vector<int> dp(n,-1);

    return f(0,st,dp,s);
}

};