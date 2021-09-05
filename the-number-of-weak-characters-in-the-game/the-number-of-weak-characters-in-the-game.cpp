class Solution
{
public:
     static bool comp(vector<int> &a, vector<int> &b)
     {
          if (a[0] == b[0])
                 return a[1] > b[1] ;
          return 
                 a[0] < b[0];
     }
     int numberOfWeakCharacters(vector<vector<int>> &properties)
     {
          sort(properties.begin(), properties.end(), comp); //sorting the array
          int mx = 0 ;   //max till now while moving from right
          int c = 0;

          for (int i = properties.size() - 1; i >= 0; i--)
          {
             if (properties[i][1] < mx) // if the second parameter is also less increase count 
                    c++;
               mx = max(mx, properties[i][1]);
          }
          return c ;
     }
};