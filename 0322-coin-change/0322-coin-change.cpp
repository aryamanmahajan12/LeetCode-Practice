class Solution {
public:
    
    int coinChange(vector<int>& coins, int amount) 
    {
        int dp[amount + 1];
        for(int i=0;i<amount+1;i++)
        {
            dp[i]=INT_MAX;
        }
        dp[0]=0;

        for(int i=1;i<=amount;i++)
        {
            for(auto c:coins)
            {
                if(c<=i)
                {
                    int sub_res = dp[i-c];
                    if(sub_res!=INT_MAX)
                    {
                        dp[i] = min (dp[i],sub_res+1);
                    }
                }
            }
        }

        if(dp[amount]!=INT_MAX)
        return dp[amount];
        return -1;
    }
};