#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int left (int p) { return p << 1 ; }
int right(int p) { return (p << 1) + 1 ; }

int n, q, l, r, ans ;
string s, L, R ;
vi a ;
vpii tree ;
unordered_map<string, int> idx ;

int get(string s)
  {
    int N=s.length(), ans=0, l, r ;
    s='#'+s ;
    bool isPal[N+1][N+1] ;
    memset(isPal, false, sizeof isPal) ;
    for(int i=1 ; i<=N ; i++) isPal[i][i]=true ;
    for(int len=2 ; len<=N ; len++)
      for(int i=1 ; i+len-1<=N ; i++)
        {
          l=i ; r=i+len-1 ;
          if(len==2) isPal[l][r]=(s[l]==s[r]) ;
          else isPal[l][r]=((s[l]==s[r])&&isPal[l+1][r-1]) ;
        }
    for(int i=1 ; i<=N ; i++)
      for(int j=i ; j<=N ; j++)
        if(isPal[i][j])
          ans++ ;
    return ans ;
  }

void build(int p, int l, int r)
  {
    if(l==r) tree[p]=mp(a[l], l) ;
    else
      {
        build(left(p), l, (l+r)/2) ;
        build(right(p), (l+r)/2 + 1, r) ;
        pii x=tree[left(p)] ;
        pii y=tree[right(p)] ;
        if(x.fi>y.fi) tree[p]=x ;
        else if(x.fi<y.fi) tree[p]=y ;
        else if(x.se<y.se) tree[p]=x ;
        else tree[p]=y ;
      }
  }

pii query(int p, int l, int r, int i, int j)
  {
    if(i>r || j<l) return mp(0, -1) ;
    if(i<=l && j>=r) return tree[p] ;
    pii x=query(left(p), l, (l+r)/2, i, j) ;
    pii y=query(right(p), (l+r)/2 + 1, r, i, j) ;
    if(x.fi>y.fi) return x ;
    else if(x.fi<y.fi) return y ;
    else if(x.se<y.se) return x ;
    else return y ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> q ;
        idx.clear() ; a.assign(n+1, 0) ; tree.assign(4*n+1, mp(0, -1)) ;
        for(int i=0 ; i<n ; i++)
          {
            cin>> s ;
            idx[s]=i ;
            a[i]=get(s) ;
          }
        build(1, 0, n-1) ;
        for(int i=0 ; i<q ; i++)
          {
            cin>> L >> R ;
            l=idx[L] ; r=idx[R] ;
            if(l>r) swap(l, r) ;
            pii temp=query(1, 0, n-1, l, r) ;
            ans=temp.se+1 ;
            cout<< ans << endl ;
          }
      }
  }
