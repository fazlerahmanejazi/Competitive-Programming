#include <bits/stdc++.h>
using namespace std ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    int n ;
    double h ;
    cin>> n >> h ;
    vector<double> height(n+1) ;
    height[n]=h ;
    for(int i=n-1 ; i>0 ; i--)
      {
        height[i]=height[i+1]*sqrt(i)/(double)sqrt(i+1) ;
      }
    for(int i=1 ; i<n ; i++)
      cout<< fixed << setprecision(12) << height[i] << " " ;
  }
