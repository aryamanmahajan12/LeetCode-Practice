class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
     string s;
     int m=0;
     uint32_t t = n;
     uint32_t ans =0;
     for(int i=0;i<=31;i++)
     {
        n=t;
        n = n>>i;
        m=1&n;
        if(m==1)s+='1';
        else s+='0';
     }
        //reverse(s.begin(),s.end());
        cout<<s<<endl;
     int j=0;
        for(int i=31;i>=0;i--)
        {
            if(s[i]=='1')
            {
                ans += 1<<j;
            }
            j++;
        }
     return ans;
    }
};