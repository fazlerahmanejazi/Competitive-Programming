#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n ;
    bool check ;
    cin>> n ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    list<int> b ;
    list<int>::iterator it ;
    b.pb(a[0]) ;
    if(n%2) check=true ;
    else check=false ;
    for(int i=1 ; i<n ; i++)
      {
        if(check)
          {
            b.pb(a[i]) ;
            check=false ;
          }
        else
          {
            b.push_front(a[i]) ;
            check=true ;
          }
      }
    it=b.begin() ;
    while(it!=b.end())
      {
        cout<< *it << " " ;
        it++ ;
      }
  }
