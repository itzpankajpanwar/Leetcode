class Solution {
public:
    int furthestBuilding(vector<int>& h, int b, int l) 
    {
        priority_queue<int> pq;
        for(int i=1;i<h.size();i++)
        {
            if( h[i]>h[i-1])
            {
                int d = h[i]-h[i-1];
                if(b>=d)
                    {
                        b-=d;
                        pq.push(d);
                    }
                else if(l>0)
                    {
                        if(!pq.empty())
                        {
                            int x = pq.top();
                            if(x>d) 
                            { 
                                b+=(x-d);
                                pq.pop();
                                pq.push(d);   
                            }   
                        }
                        l--;
                    }
                else
                    return i-1;
            }
        }
    return h.size()-1;
    }
};