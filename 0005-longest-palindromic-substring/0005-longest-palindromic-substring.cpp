class Solution 
{
public:

    string lcs(string a, string b)
    {
        int n = a.size();
        bool dp[n][n];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                dp[i][j]=false;
            }
        }

        int maxL,start;

        for(int i=0;i<n;i++)
        {
        dp[i][i]=true;
        start=i;
        maxL=1;
        }
        
        for(int i=0;i<n-1;i++)
        {
            if(a[i]==a[i+1])
            {
            dp[i][i+1]=true;
            start=i;
            maxL=2;
            }
        }

        for(int k=3; k<=n; ++k)
        {
            for(int i=0;i<n-k+1;++i)
            {
                int j = i+k-1;
                if(dp[i+1][j-1]==true && a[i]==a[j])
                {
                    dp[i][j]=true;
                    if(k>maxL)
                    {
                        start=i;
                        maxL=k;
                    }
                }
            }
        }
        
        cout<<"maxL: "<<maxL<<endl;
        string now = a.substr(start,maxL);
        return now;
    }

    string longestPalindrome(string s) 
    {
        
        string ans = lcs(s,s);
        return ans;
    }

};