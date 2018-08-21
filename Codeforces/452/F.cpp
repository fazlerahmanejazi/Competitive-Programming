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

int n, q, x, l, r ;
char c ;
string s ;
map<char, set<int>> pos ;
vi tree, del ;

int query(int i)
  {
    int temp=0 ;
    for( ; i>=0 ; i=(i&(i+1))-1) temp+=tree[i] ;
    return temp ;
  }

void update(int i, int val)
  {
    for( ; i<=n ; i=(i|(i+1))) tree[i]+=val ;
  }

int get(int x)
  {
    int l=1, r=n, m, ans=1, y ;
    while(l<=r)
      {
        m=(l+r)/2 ;
        y=m-query(m) ;
        if(y<x) l=m+1 ;
        else r=m-1, ans=m ;
      }
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q >> s ;
    tree.assign(n+1, 0) ;
    for(int i=0 ; i<n ; i++) pos[s[i]].insert(i+1) ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> l >> r >> c ;
        l=get(l) ; r=get(r) ;
        auto &idx=pos[c] ;
        auto it=idx.lower_bound(l) ;
        while(it!=idx.end() && (*it)<=r)
          {
            update(*it, 1) ;
            del.pb(*it) ;
            it=idx.erase(it) ;
          }
      }
    sort(all(del)) ;
    for(int i=1, j=0 ; i<=n ; i++)
      if(j<del.size() && del[j]==i) j++ ;
      else cout<< s[i-1] ;
  }
