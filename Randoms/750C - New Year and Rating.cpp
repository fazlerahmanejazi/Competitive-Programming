#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod (lli)1000000007
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
    int n, c, d, U, L, pre=0 ;
    cin>> n ;
    U=inf ;
    L=-inf ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> c >> d ;
        if(d==1) L=max(L, 1900-pre) ;
        else U=min(U, 1899-pre) ;
        pre+=c ;
      }
    if(L>U) cout<< "Impossible" ;
    else if(U==inf) cout<< "Infinity" ;
    else cout<< U+pre ;
  }
