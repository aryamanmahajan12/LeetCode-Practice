class Solution {
public:
    string addBinary(string a, string b) 
    {string str;
        if(a.size()>b.size())
        {
            string s;
            char c = '0';
            int i = a.size()-1;
            int j = b.size()-1;
            for(i=a.size()-1;i>=0 && j>=0;i--,j--)
            {
                if(a[i]=='1'&&b[j]=='1' && c=='1')
                {
                    s+='1';
                    c='1';
                }
                else if(a[i]=='1'&&b[j]=='1'&&c=='0')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='1'&&b[j]=='0'&&c=='1')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='1'&&b[j]=='0'&& c=='0')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[j]=='1'&&c=='1')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='0'&&b[j]=='1'&&c=='0')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[j]=='0'&&c=='1')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[j]=='0'&& c=='0')
                {
                    s+='0';
                    c+'0';
                }
                
            }
            cout<<i<<endl;
            while(i>=0)
            {cout<<i<<endl;
                if(a[i]=='1'&&c=='1')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='1'&&c=='0')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&c=='1')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&c=='0')
                {
                    s+='0';
                    c='0';
                }
                i--;
            }
            if(c=='1')s+='1';

            reverse(s.begin(),s.end());
            return s;
        }
        if(a.size()<b.size())
        {
            string s;
            char c = '0';
            int j = b.size()-1;
            int i=0;
            for(int i=a.size()-1;i>=0 && j>=0;i--,j--)
            {
                if(a[i]=='1'&&b[j]=='1' && c=='1')
                {
                    s+='1';
                    c='1';
                }
                else if(a[i]=='1'&&b[j]=='1'&&c=='0')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='1'&&b[j]=='0'&&c=='1')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='1'&&b[j]=='0'&& c=='0')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[j]=='1'&&c=='1')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='0'&&b[j]=='1'&&c=='0')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[j]=='0'&&c=='1')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[j]=='0'&& c=='0')
                {
                    s+='0';
                    c+'0';
                }
                
            }
            while(j>=0)
            {
                if(b[j]=='1'&&c=='1')
                {
                    s+='0';
                    c='1';
                }
                else if(b[j]=='1'&&c=='0')
                {
                    s+='1';
                    c='0';
                }
                else if(b[j]=='0'&&c=='1')
                {
                    s+='1';
                    c='0';
                }
                else if(b[j]=='0'&&c=='0')
                {
                    s+='0';
                    c='0';
                }
                j--;
            }
            if(c=='1')
            s+='1';

            reverse(s.begin(),s.end());
            return s;
        }
        else
        {
            string s;
            char c = '0';
            for(int i=a.size()-1;i>=0;i--)
            {
                if(a[i]=='1'&&b[i]=='1' && c=='1')
                {
                    s+='1';
                    c='1';
                }
                else if(a[i]=='1'&&b[i]=='1'&&c=='0')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='1'&&b[i]=='0'&&c=='1')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='1'&&b[i]=='0'&& c=='0')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[i]=='1'&&c=='1')
                {
                    s+='0';
                    c='1';
                }
                else if(a[i]=='0'&&b[i]=='1'&&c=='0')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[i]=='0'&&c=='1')
                {
                    s+='1';
                    c='0';
                }
                else if(a[i]=='0'&&b[i]=='0'&& c=='0')
                {
                    s+='0';
                    c+'0';
                }
                
            }
            if(c=='1')s+='1';
            reverse(s.begin(),s.end());
            return s;
        }
        return "0";   
    }
};
