class Solution {
public:
    int hammingWeight(int n) {
        int count =0;
        int k = n;
        int m=1;
        for(int i=0;i<=31;i++)
        {
            n=n>>i;
            count += n&1;
            n=k;
            m=1;
        }
        return count;
    }
};