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

lli n, c, x, tot, num, T, l, r, m ;
vlli q ;
set<lli> a, b ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> c ;
    q.resize(n) ;
    for(int i=0 ; i<n ; i++) cin>> q[i], tot+=q[i] ;
    b=ceil((1.0*tot)/(1.0*c)) ;
    sort(all(q)) ;
    reverse(all(q)) ;
    for(int i=0 ; i<q ; i++) if(q[i]!=c) a.insert(q[i]) ;
    for(int i=q ; i<n ; i++) if(q[i]!=c) b.insert(q[i]) ;
    reverse(all(a)) ;
    for(int i=0 ; i<b.size() ; i++)
      {

      }
  }
