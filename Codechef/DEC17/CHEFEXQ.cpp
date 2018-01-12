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
const int blockSize=320 ; //Using blockSize as 1000 uses less memory and passes the time limit

int n, q, x, idx, t, y ;
vi a(N, 0), b(N), lazy(320, 0) ;
int cnt[320][1000000] ;

int get(int idx)
  {
    return idx/blockSize ;
  }

int lazyUpdate(int p, int idx, int x)
  {
    int B=get(idx) ;
    while(p<=n && get(p)==get(idx))
      {
        cnt[B][a[p]]-- ;
        a[p]^=x ;
        cnt[B][a[p]]++ ;
        p++ ;
      }
    return p ;
  }

void update(int idx, int x)
  {
    int p=idx ;
    p=lazyUpdate(p, idx, x) ;
    while(p<=n && get(p)<=get(n)) lazy[get(p)]^=x, p+=blockSize ;
  }

int query(int idx, int x)
  {
    int p=max(get(idx)*blockSize, 1), res=0, B=get(idx) ;
    if(lazy[B]) lazyUpdate(p, idx, lazy[B]), lazy[B]=0 ;
    p=idx ;
    while(p>=1 && get(p)==get(idx))
      {
        if(a[p]==x) res++ ;
        p-- ;
      }
    while(p>=1)
      {
        B=get(p) ;
        res+=cnt[B][x^lazy[B]] ;
        p-=blockSize ;
      }
    return res ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> a[i] ;
        b[i]=a[i] ;
        a[i]^=a[i-1] ;
        cnt[get(i)][a[i]]++ ;
      }
    for(int i=1 ; i<=q ; i++)
      {
        cin>> t >> idx >> x ;
        if(t==1)
          {
            y=x^b[idx] ;
            b[idx]=x ;
            update(idx, y) ;
          }
        else cout<< query(idx, x) << endl ;
      }
  }
