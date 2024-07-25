class Solution 
{
public:
    bool isInterleave(string s1, string s2, string s3) 
    {
        if(s3.size() != s1.size() + s2.size()) return false;

        int n = s1.size();
        int m = s2.size();

        bool dp[n+1][m+1];
        for(int i=0;i<n+1;i++)
        {
            for(int j=0;j<m+1;j++)
            {
                dp[i][j]=false;
            }
        }

        dp[n][m]=true;

        for(int i=n;i>-1;i--)
        {
            for(int j=m;j>-1;j--)
            {
                if(i<n && s1[i]==s3[i+j] && dp[i+1][j]==true)
                dp[i][j]=true;
                if(j<m && s2[j]==s3[i+j]&& dp[i][j+1]==true)
                dp[i][j]=true;
            }
        }
        return dp[0][0];

    }
};