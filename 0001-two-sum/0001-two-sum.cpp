class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> v;
        multimap<int,int> mp;int flag=0,sum=0;
        for(int i=0;i<nums.size();i++)
        {
            mp.insert({nums[i],i});
        }   

        auto p1 = mp.begin();
        auto p2 = mp.end();
        p2--;

        while(p1!=p2)
        {   sum=p1->first + p2->first;

            if(sum==target)
            {
                v.push_back(p1->second);
                v.push_back(p2->second);
                flag=1;
                break;
            }
            else if(sum>target)
            {
                p2--;
            }
            else if(sum<target)
            {
                p1++;
            }
            
            
        }

        return v;




    

       
    }
};