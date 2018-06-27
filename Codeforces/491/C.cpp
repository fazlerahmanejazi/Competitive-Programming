#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define pi acos(-1.0)
#define eps 1e-8
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

bool check(lli m, lli n)
  {
    lli res=0, M=(n+1)/2 ;
    while(n)
      {
        res+=min(n, m) ;
        n-=min(n, m) ;
        if(res>=M) return true ;
        n-=n/10 ;
      }
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, l, r, m ;
    cin>> n ;
    l=1 ; r=n ;
    while(l<r)
      {
        m=(l+r)/2 ;
        if(check(m, n)) r=m ;
        else l=m+1 ;
      }
    cout<< l ;
  }
