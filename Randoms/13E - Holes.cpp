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

int n, m, a, b, t, x, y, c, res, last, ans[N], power[N], cnt[N], nxt[N] ;

int get(int idx)
  {
    return idx/blockSize ;
  }

void preprocess()
  {
    cnt[n+1]=0 ; nxt[n+1]=ans[n+1]=n+1 ;
    for(int x=n ; x>=1 ; x--)
      {
        y=min(x+power[x], n+1) ;
        if(get(y)==get(x)) nxt[x]=nxt[y], cnt[x]=1+cnt[y] ;
        else nxt[x]=y, cnt[x]=1 ;
        ans[x]=(y>n)?x:ans[y] ;
      }
  }

void update(int a, int b)
  {
    power[a]=b ;
    for(int x=a ; x>=1 && get(x)==get(a) ; x--)
      {
        y=min(x+power[x], n+1) ;
        if(get(y)==get(x)) nxt[x]=nxt[y], cnt[x]=1+cnt[y] ;
        else nxt[x]=y, cnt[x]=1 ;
        ans[x]=(y>n)?x:ans[y] ;
      }
  }

int query(int a)
  {
    res=0 ; x=a ;
    while(x<=n) res+=cnt[x], last=x, x=nxt[x] ;
    x=ans[last] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    for(int i=1 ; i<=n ; i++) cin>> power[i] ;
    preprocess() ;
    for(int i=0 ; i<m ; i++)
      {
        cin>> t ;
        if(!t)
          {
            cin>> a >> b ;
            update(a, b) ;
          }
        else
          {
            cin>> a ;
            query(a) ;
            cout<< x << " " << res << endl ;
          }
      }
  }
