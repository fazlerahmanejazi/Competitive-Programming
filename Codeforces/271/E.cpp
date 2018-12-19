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

int n, d, x, a[200000] ;
pii tree[400000], dp[200000] ;

pii query(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return {0, 0} ;
    if(s>=qs && e<=qe) return tree[idx] ;
    return max(query(2*idx, s, (s+e)/2, qs, qe), query(2*idx+1, (s+e)/2+1, e, qs, qe));
  }

void updateNode(int idx, int s, int e, int pos, int val)
  {
    if(pos<s || pos>e) return ;
    if(s==e)
      {
        tree[idx]=max(tree[idx], {val, pos}) ;
        return ;
      }
    updateNode(2*idx, s, (s+e)/2, pos, val) ;
    updateNode(2*idx+1, (s+e)/2+1, e, pos, val) ;
    tree[idx]=max(tree[2*idx],tree[2*idx+1]) ;
  }


int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> d ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    for(int i=n ; i>=1 ; i--)
      {
        dp[i]={1, 0} ;
        pii q=query(1, 1, n, i+1, n) ;

      }
  }
