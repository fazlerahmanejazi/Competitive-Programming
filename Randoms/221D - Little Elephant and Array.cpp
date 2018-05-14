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

const int N=100005 ;
const int blockSize=sqrt(N) ;

int n, m, l, r, x, idx, L, R, res ;
vi a, ans, cnt(N) ;
vector<tuple<int, int, int, int>> q ;

int get(int idx)
  {
    return idx/blockSize ;
  }

void add(int x)
  {
    if(x>n) return ;
    if(cnt[x]==x) res-- ;
    cnt[x]++ ;
    if(cnt[x]==x) res++ ;
  }

void del(int x)
  {
    if(x>n) return ;
    if(cnt[x]==x) res-- ;
    cnt[x]-- ;
    if(cnt[x]==x) res++ ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    a.resize(n) ; ans.resize(m) ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> l >> r ;
        l-- ; r-- ;
        q.pb(mt(get(l), r, l, i)) ;
      }
    sort(all(q)) ;
    L=R=0 ; add(a[0]) ;
    for(int i=0 ; i<m ; i++)
      {
        tie(ignore, r, l, idx)=q[i] ;
        while(L<l) del(a[L++]) ;
        while(L>l) add(a[--L]) ;
        while(R<r) add(a[++R]) ;
        while(R>r) del(a[R--]) ;
        ans[idx]=res ;
      }
    for(int i=0 ; i<m ; i++) cout<< ans[i] << endl ;
  }
