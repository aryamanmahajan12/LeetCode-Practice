class Solution {
public:
    bool searchMatrix(vector<vector<int>>& nums, int target) 
    {
        int m = nums.size();
        int n = nums[0].size();

        int rlow=0;
        int rhigh=m-1;
        int clow=0;
        int chigh=n-1;
        int idx=-1;
        int rmid,cmid;
        while(rlow<=rhigh)
        {
            rmid=(rlow+rhigh)/2;

            if(target>=nums[rmid][0])
            {
                idx=rmid;
                rlow=rmid+1;
            }
            else
            {
                rhigh=rmid-1;
            }
        }
        if(idx==-1)
        return false;
        int ans=-1;
        while(clow<=chigh)
        {
            cmid=(clow+chigh)/2;
            if(nums[idx][cmid]==target)
            return true;

            if(target>nums[idx][cmid])
            {
                clow=cmid+1;
            }
            else
            {
                chigh=cmid-1;
            }
        }

        return false;

    }
};