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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    vector<tuple<int, int, int, int>> tc ;
    for(int n=1 ; n<=10 ; n++)
      for(int m=1 ; m<=n*n ; m++)
        for(int d=0 ; d<=n ; d++)
          for(int D=d ; D<=n ; D++)
            tc.pb(mt(n, m, d, D)) ;
    cout<< tc.size() << endl ;
    for(int i=0 ; i<tc.size() ; i++)
      {
        int n, m, d, D ;
        tie(n, m , d, D)=tc[i] ;
        cout<< n << " " << m << " " << d << " " << D << endl ;
      }
  }
