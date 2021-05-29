class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
    vector<int> st;
    for(auto &x: asteroids)
    {
        if(st.empty()) st.push_back(x);
        else
        {
            while( st.size()> 0 && ( (st.back()>0 && x<0) or (st.back()>0 && x<0) ) )
                {
                    {
                        if( st.back() == -x)  { st.pop_back(); x=0; }
                        else if ( abs(x) > st.back() )  { st.pop_back(); }
                        else
                            {  x = st.back() ;  st.pop_back();  }      
                    }

                }    
            if(x!=0)
                st.push_back(x);
         }
    }
    return st;
    }
};