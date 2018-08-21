#include <bits/stdc++.h>
using namespace std ;
int main()
{  float h, m ;
   cin>> h >> m ;
   h= h*30.0 + 0.5*m ;
   m=m*6.0 ;
   cout<< abs(h-m) ;
   return 0 ;
}
