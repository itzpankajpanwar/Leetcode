class Cashier {
public:
    int n , d , gg ;
    unordered_map<int,int> mp;
    Cashier(int _n, int discount, vector<int>& pr, vector<int>& pi)
    {
        n = _n;
        gg=n;
        d = discount ; 
        for(int i=0 ; i < pr.size() ; i++)
            mp[pr[i]]=pi[i];
    }
    
    
    double getBill(vector<int> product, vector<int> amount) 
    {   gg--;
        double bill=0;
        for(int i=0;i<product.size(); i++)
            bill += mp[product[i]]*amount[i];
        if(gg==0)
        {   bill = bill - ((bill*d)/100);
            gg=n; 
        }
        return bill;
    }
};

/**
 * Your Cashier object will be instantiated and called as such:
 * Cashier* obj = new Cashier(n, discount, products, prices);
 * double param_1 = obj->getBill(product,amount);
 */