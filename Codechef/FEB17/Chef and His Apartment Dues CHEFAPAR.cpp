#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  long long int T, n, ans, it, data ;
  cin>> T ;
  while(T--)
    {
      cin>> n ;
      it=0 ;
      ans=0 ;
      for(int i=0 ; i<n ; i++)
        {
          cin>> data ;
          if(data==1)
            {
              if(i>it)
                  ans+=100 ;
              it++ ;
            }
        }
      ans+=1100*(n-it) ;
      cout<< ans << endl ;
    }
  return 0 ;
}
