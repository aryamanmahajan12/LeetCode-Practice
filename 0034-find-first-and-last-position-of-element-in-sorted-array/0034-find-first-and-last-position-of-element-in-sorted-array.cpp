class Solution 
{
public:

int firstocc(vector<int>&nums,int target)
{
    int n =nums.size();
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    int ans=-1;
    while(low<=high)
    {
        mid=(low+high)/2;

        if(nums[mid]==target)
        {
            ans=mid;
            high=mid-1;
        }
        else if(target<nums[mid])
        {
            high=mid-1;
        }
        else if(target>nums[mid])
        {
            low=mid+1;
        }
    }
    return ans;
}
int lastocc(vector<int>&nums,int target)
{
    int n =nums.size();
    int low=0;
    int high=n-1;
    int mid=(low+high)/2;
    int ans=-1;
    while(low<=high)
    {
        mid=(low+high)/2;

        if(nums[mid]==target)
        {
            ans=mid;
            low=mid+1;
        }
        else if(target<nums[mid])
        {
            high=mid-1;
        }
        else if(target>nums[mid])
        {
            low=mid+1;
        }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) 
    {
     vector<int>vec;
     int a =firstocc(nums,target);
     int b=lastocc(nums,target);

     vec.push_back(a);
     vec.push_back(b);

     return vec;   
    }
};