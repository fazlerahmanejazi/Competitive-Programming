#include <bits/stdc++.h>
using namespace std ;

vector<int> child ;
int n, k, leader, remaining ;
bool space=false ;

int next(int curr)
  {
    if(curr==n) return 1 ;
    else return curr+1 ;
  }

int game(int q, int pos)
  {
    q=q%remaining ;
    for(int i=1 ; i<=q ; )
      {
        pos=next(pos) ;
        if(child[pos]<=n)
          i++ ;
      }
    child[pos]=101 ;
    remaining-- ;
    if(space) cout<< " " ;
    cout<< pos ;
    space=true ;
    for(int i=0 ; i<n ; i++)
      {
        if(child[next(pos)]<=n) return next(pos) ;
        else pos=next(pos) ;
      }
    return 0 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> n >> k ;
    leader=1 ;
    remaining=n ;
    vector<int> a(k+10), ans ;
    child.resize(n+10) ;
    for(int i=1 ; i<=n ; i++)
      child[i]=i ;
    for(int i=0 ; i<k ; i++)
      cin>> a[i] ;
    for(int i=0 ; i<k ; i++)
      leader=game(a[i], leader) ;
    return 0 ;
  }
