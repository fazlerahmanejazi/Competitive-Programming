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

const int N=200005 ;
const int blockSize=sqrt(N) ;

lli n, t, l, r, x, idx, L, R, res ;
vlli a, ans, cnt(1000005) ;
vector<tuple<lli, lli, lli, lli>> q ;

int get(int idx)
  {
    return idx/blockSize ;
  }

void add(lli x)
  {
    res+=x*(2*(cnt[x]++)+1) ;
  }

void del(lli x)
  {
    res+=x*(-2*(cnt[x]--)+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> t ;
    a.resize(n) ; ans.resize(t) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=0 ; i<t ; i++)
      {
        cin>> l >> r ;
        l-- ; r-- ;
        q.pb(mt(get(l), r, l, i)) ;
      }
    sort(all(q)) ;
    L=R=0 ; add(a[0]) ;
    for(int i=0 ; i<t ; i++)
      {
        tie(ignore, r, l, idx)=q[i] ;
        while(L<l) del(a[L++]) ;
        while(L>l) add(a[--L]) ;
        while(R<r) add(a[++R]) ;
        while(R>r) del(a[R--]) ;
        ans[idx]=res ;
      }
    for(int i=0 ; i<t ; i++) cout<< ans[i] << endl ;
  }
