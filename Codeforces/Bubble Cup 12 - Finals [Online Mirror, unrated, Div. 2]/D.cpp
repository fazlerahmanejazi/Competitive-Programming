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
    lli n, k, a, x[100005], c[100005], money=0 ;
    multiset<lli> unused ;
    cin>> n >> k ;
    for(int i=1 ; i<=n ; i++) cin>> x[i] ;
    cin>> a ;
    for(int i=1 ; i<=n ; i++) cin>> c[i] ;
    for(int i=1 ; i<=n ; i++)
      {
        unused.insert(c[i]) ;
        while(!unused.empty() && k<x[i])
          {
            auto temp=unused.begin() ;
            k+=a ;
            money+=*temp ;
            unused.erase(temp) ;
          }
        if(k<x[i]) return cout<< -1, 0 ;
      }
    cout<< money ;
  }
