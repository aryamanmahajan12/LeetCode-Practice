class Solution 
{
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) 
    {
        vector<vector<int>> vec;

        priority_queue<pair<int, pair<int,int>>> mxhp;
        int sum=0;

        for(int i=0;i<nums1.size();i++)
        {
            for(int j=0;j<nums2.size();j++)
            {
                sum = nums1[i] + nums2[j];
                
                if(mxhp.size()<k)
                {
                    mxhp.push(make_pair(sum, make_pair(nums1[i], nums2[j])));
                }
                else if(sum < mxhp.top().first)
                {
                    mxhp.pop();
                    mxhp.push(make_pair(sum, make_pair(nums1[i], nums2[j])));
                }
                else if(sum >= mxhp.top().first)
                {
                    break;
                }
            }
        }

        for(int i=1;i<=k;i++)
        {
            vec.push_back({mxhp.top().second.first,mxhp.top().second.second});
            mxhp.pop();
        }

        return vec;
    }
};