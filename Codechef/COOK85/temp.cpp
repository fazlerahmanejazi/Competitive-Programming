#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    int T ;
    cin>> T ;
    while(T--)
      {
        long double n, v1, v2, timeStairs, timeElev ;
        cin>> n >> v1 >> v2 ;
        timeStairs=sqrt(2)*v1 ;
        timeElev=v2 ;
        if(timeStairs>timeElev) cout<< "Stairs" << endl ;
        else cout<< "Elevator" << endl ;
      }
  }
