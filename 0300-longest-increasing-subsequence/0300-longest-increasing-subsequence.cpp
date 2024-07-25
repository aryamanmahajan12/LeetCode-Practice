class Solution 
{
public:
    int lengthOfLIS(vector<int>& nums) 
    {
        if(nums.size()==1) return 1;

        int lis[nums.size()];
        lis[0]=1;
        
        for(int i=1;i<nums.size();i++)
        {   
            lis[i]=1;
            for(int j=i-1;j>=0;j--)
            {
                if(nums[i]>nums[j])
                {
                    int var = lis[j]+1;
                    lis[i] = max(lis[i],var);
                }
            }
        }

        return *max_element(lis,lis+nums.size());
    }
};