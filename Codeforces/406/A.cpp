#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ;
    int a, b, c, d, r, m ;
    cin>> a >> b ;
    cin>> c >> d ;
    if(abs(b-d)%2==1)
    	{
    		if(a%2==0 && c%2==0)
    			{
    				cout<< -1 ;
    				return 0 ;
    			}
    	}
    for(int i=0 ; i<10000 ; i=i+a)
      for(int j=0 ; j<10000 ; j=j+c)
        {
          r=b+i ;
          m=d+j ;
          if(r==m)
            {
              cout<< r ;
              return 0 ;
            }
        }
    cout<< -1 ;
    return 0 ;
  }
