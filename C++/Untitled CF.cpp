#include <bits/stdc++.h>
using namespace std ;
int main()
{ queue <int> t ;
  queue <string> d ;
  string D="left" ;
  int Cases ;
  long int T, temp ;
  int n ;
  string Temp ;
  cin>> Cases ;
  while(Cases--)
  { int c=0 ;
    cin>> T >> n ;
    T=T*100 ;
    while(n--)
    {
      cin>> temp >> Temp ;
      t.push(temp) ;
      d.push(Temp) ;
    }

    while(t.empty())
    { temp=0 ;
     while(temp+t.front()<=T)
     {
        if(d.front()==D)
       { temp=temp+t.front() ;
         d.pop() ;
         t.pop() ;
       }
       else
       {
         c++ ;
         if(D=="right") D="left" ;
         else D="right" ;
       }
     }
     c++ ;
     if(D=="right") D="left" ;
     else D="right" ;
    }
  cout<< c << endl ;
  }
  return 0 ;
}
