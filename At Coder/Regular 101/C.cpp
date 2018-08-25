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
    lli n, k, x, ans=INF ;
    vlli left, right ;
    cin>> n >> k ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> x ;
        if(x>0) right.pb(x) ;
        else left.pb(-x) ;
      }
    reverse(all(left)) ;
    if(left.size()>=k) ans=min(ans, left[k-1]) ;
    if(right.size()>=k) ans=min(ans, right[k-1]) ;
    for(int i=0 ; i<right.size() ; i++) if(k-i-2>=0 && k-i-2<left.size()) ans=min({ans, 2*right[i]+left[k-i-2], right[i]+2*left[k-i-2]}) ;
    cout<< ans ;
  }
