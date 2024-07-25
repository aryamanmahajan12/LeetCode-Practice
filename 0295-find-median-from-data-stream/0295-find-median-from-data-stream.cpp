class MedianFinder 
{
  
public:

    priority_queue<int> maxhp;//small elements
    priority_queue<int,vector<int>, greater<int>> minhp; //big elements

    MedianFinder() 
    {
        
    }
    
    void addNum(int num) 
    {
        maxhp.push(num);
      
        if(!maxhp.empty() && !minhp.empty() && maxhp.top() > minhp.top())
        {
            int a =maxhp.top();
            maxhp.pop();
            minhp.push(a);
        }

        if (maxhp.size() > minhp.size() + 1) 
        {
        minhp.push(maxhp.top());
        maxhp.pop();
        } 
        else if (minhp.size() > maxhp.size() +1) {
            maxhp.push(minhp.top());
            minhp.pop();
        }
    }
    
    double findMedian() 
    {
        if(maxhp.size()==minhp.size())
        {
            double ans = maxhp.top() + minhp.top();
            ans = ans/2;
            return ans;
        }

        else
        {
            if(maxhp.size()>minhp.size())
            {
                return maxhp.top();
            }
            return minhp.top();
        } 
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */