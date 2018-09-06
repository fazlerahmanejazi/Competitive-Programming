#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
//#define endl '\n'
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

lli n, k, m, l, r, x ;
string q ;

bool query(lli L, lli R)
  {
    cout<< L << " " << R << endl ;
    cin>> q ;
    return q[0]=='Y' ;
  }

void reduceRange()
  {
    while(r-l>6*k+10)
      {
        m=(l+r)/2 ;
        if(query(l, m)) l=max(l-k, 1LL), r=min(m+k, n) ;
        else l=max(m-k, 1LL), r=min(r+k, n) ;
      }
    x=l+(rand()%(r-l+1)) ;
    if(query(x, x)) exit(0) ;
    l=max(l-k, 1LL) ;
    r=min(r+k, n) ;
  }

int main()
  {
    //ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    srand(time(0)) ;
    cin>> n >> k ;
    l=1 ; r=n ;
    while(1) reduceRange() ;
  }
