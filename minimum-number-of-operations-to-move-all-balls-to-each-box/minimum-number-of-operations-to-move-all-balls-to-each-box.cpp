class Solution {
public:
    vector<int> minOperations(string boxes) {
       
    vector<int> res;
    
    for(int i=0;i<boxes.size();i++)
    {   
        int val=0;
        for(int j=0;j<boxes.size();j++)
        {
            if(i==j) continue;
            if(boxes[j]=='1')
                val+= abs(i-j);
        }
        res.push_back(val);
    }
    return res;
    }
};