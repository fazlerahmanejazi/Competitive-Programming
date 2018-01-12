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

using namespace std;

const int N=200000 ;
const int TREE_SIZE=N<<2 ;

int n, q, l, r, x, cnt=0, s, last=1 ;
lli sum=0 ;
bool check ;
vi a ;
vvi v ;
vi tree, ans, to, from ;
vb avail ;
map<pii, bool> done ;

void init(int n)
  {
    tree.clear() ; tree.resize(n<<2) ;
    ans.assign(n+1, 1) ;
    to.assign(n+1, 0) ;
    from.assign(n+1, 0) ;
    avail.assign(n+1, true) ;
    a.assign(n+1, 1) ;
    v.clear() ; v.resize(n+1) ;
    done.clear() ;
    check=true ;
  }

void update(int a, int b, int pos, int node, int value)
  {
    if(a>b || a>pos || b<pos) return ;
    if(a==b)
      {
        tree[node]=value ;
        return ;
      }
    update(a, (a+b)>>1, pos, node<<1, value) ;
    update(((a+b)>>1)+1, b, pos, (node<<1)|1, value) ;
    tree[node]=min(tree[node<<1], tree[(node<<1)|1]) ;
  }

int query(int a, int b, int node, int value)
  {
    if(a==b) return a ;
    if(tree[node<<1]<value) return query(a, (a+b)>>1, node<<1, value) ;
    else return query(((a+b)>>1)+1, b, (node<<1)|1, value) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int T ;
    cin>> T ;
    while(T--)
      {
        cin>> n >> q ;
        init(n+1) ;
        for(int i=1 ; i<=q ; i++)
          {
            cin>> l >> r ;
            to[l]++ ;
            from[r]++ ;
            if(done[mp(l, r)]) check=false ;
            else done[mp(l, r)]=true ;
            if(l>=r) check=false ;
            else v[r-1].pb(l) ;
          }
        for(int i=1 ; i<=n ; i++)
          {
            update(1, n+1, a[i], 1, i) ;
            sort(all(v[i])) ;
            if(v[i].size()<=1) ans[i+1]=a[i+1]=last ;
            else
              {
                s=v[i][0] ;
                x=query(1, n+1, 1, s+1) ;
                ans[i+1]=a[i+1]=x ;
                last=x ;
              }
          }
         avail[a[n]]=false ; sum=0, cnt=1 ;
         for(int i=n-1 ; i>=0 ; i--)
           {
             sum+=cnt ;
             if(cnt!=to[i]) check=false ;
             if(avail[a[i]]) avail[a[i]]=0, cnt++ ;
           }
         if(sum!=q) check=false ;
        if(check)
          {
            for(int i=1 ; i<=n ; i++)
              cout<< ans[i] << " " ;
            cout<< endl ;
          }
        else cout<< -1 << endl ;
      }
  }
