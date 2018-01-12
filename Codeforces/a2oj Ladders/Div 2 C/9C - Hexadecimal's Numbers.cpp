#include <bits/stdc++.h>
using namespace std ;

int n, c=0 ;

void solve(int x)
  {
    if(x>n) return ;
    c++ ;
    solve(x*10+1) ;
    solve(x*10) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ;
    cin>> n ;
    solve(1) ;
    cout<< c ;
  }
