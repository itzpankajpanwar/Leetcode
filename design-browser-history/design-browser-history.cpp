class BrowserHistory {
public:
    
    vector<string> vct;
    int lp=0 ,cp=0;
    BrowserHistory(string homepage)
    {   
        for(int i=0;i<5001;i++)
            vct.push_back("");
        vct[0] = homepage ;
        lp=0;
        cp=0;
        //cout<<cp<<"   "<<lp<<endl;
    }
    
    void visit(string url)
    {
        vct[cp+1]=url;
        cp++;
        lp=cp;
       // cout<<cp<<"   "<<lp<<endl;
    }
    
    string back(int steps)
    {
        if(cp-steps < 0 )
        {
            cp=0;
            return vct[0];
        }  
        cp=cp-steps;
       // cout<<cp<<"   "<<lp<<endl;
        return vct[cp]; 
        
    }
    
    string forward(int steps) {
        if(cp+steps > lp)
        {
            cp=lp;
            return vct[lp];
        }
        cp += steps;
       // cout<<cp<<"   "<<lp<<endl;
        return vct[cp];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */