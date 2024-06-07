class LRUCache 
{
public:
    int maxsize=0;
    list<int> order;
    unordered_map<int, pair<int,list<int>::iterator>>umap;

    LRUCache(int capacity) 
    {
        this->maxsize=capacity;
        this->order.clear();
        this->umap.clear();
    }

    void alter(int key)
    {
        auto it  = umap.find(key);
        order.push_front(key);
        order.erase(umap[key].second);
        it->second.second=order.begin();
    }

    int get(int key) 
    {
       if(umap.find(key)==umap.end())
       {
            return -1;
       }
       else
       {
        alter(key);
        return umap[key].first;
       }
    }
    
    void put(int key, int value) 
    {
        if(umap.find(key)==umap.end())
        {
            if(umap.size()==maxsize)
            {
                int d = order.back();
                umap.erase(d);
                order.pop_back();
            }
            order.push_front(key);
        }
        
        else
        {
            alter(key);
        }
   
          umap[key]=make_pair(value,order.begin());
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */