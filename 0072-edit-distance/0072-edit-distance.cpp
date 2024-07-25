class Solution {
public:
int minn(int x, int y, int z) { return min(min(x, y), z); }
    int minDistance(string word1, string word2) 
    {
        if(word1=="") return word2.length();
        int n = word1.length();
        int m = word2.length();

        int dp[n+1][m+1];

        dp[0][0]=0;
        for(int i=1;i<=m;i++)
        {
            dp[0][i] = i;
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=i;
        }

        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1] == word2[j-1])
                dp[i][j] = dp[i-1][j-1];
                else
                {
                    int temp  = 1 + minn(dp[i-1][j],dp[i-1][j-1], dp[i][j-1]);
                    dp[i][j]=temp;

                }
            }
        }

        return dp[n][m];
    }
};