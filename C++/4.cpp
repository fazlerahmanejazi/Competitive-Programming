#include <bits/stdc++.h>
using namespace std ;

int main()
{
  ios_base::sync_with_stdio (false) ;
  long int n, k, a, b, temp ;
  cin>> n >> k >> a >> b ;
  vector<char> ans ;

  if(k>=a && k>=b)
   {
   	for(long int i=0 ; i<a ; i++)
   	  cout<< "G" ;
   	for(long int i=0 ; i<b ; i++)
   	  cout<< "B" ;
   	 return 0 ;
   }
   long int i=0 ;
  while(i<n)
  {
    if(b>=a)
    { temp=1 ;
      while(temp<=k && b>=a && b!=0)
      { if(b!=0)
        { ans.push_back('B') ;
          b-- ;
          temp++ ;
          i++ ;
        }
      }
      if(a!=0 && temp>k) { ans.push_back('G')  ; a-- ;i++ ; temp=1 ; }
      else if(i<n) { cout<< "NO" ; return 0 ; }
    }
    else
    {
      temp=1 ;
        while(temp<=k && a>=b && a!=0)
        { if(a!=0)
          { ans.push_back('G') ;
            a-- ;
            temp++ ;
            i++ ;
          }
        }
        if(b!=0 && temp>k) { ans.push_back('B') ; b-- ; i++ ; temp=1 ; }
        else if(i<n) { cout<< "NO" ; return 0 ; }
    }
  }
  for(int i=0 ; i<n ; i++)
   cout<< ans[i] ;

  return 0 ;
}
