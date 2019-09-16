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

const int N=250000 ;
int n, p, q, a[N], pay[N], tree[4*N], t, x ;

void buildTree(int idx, int s, int e)
  {
    if(s>e) return ;
    if(s==e)
      {
        tree[idx]=pay[s] ;
        return ;
      }
    buildTree(2*idx, s, (s+e)/2) ;
    buildTree(2*idx+1, (s+e)/2+1, e) ;
    tree[idx]=max(tree[2*idx], tree[2*idx+1]) ;
  }

int query(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return 0 ;
    if(s>=qs && e<=qe) return tree[idx] ;
    return max(query(2*idx, s, (s+e)/2, qs, qe), query(2*idx+1, (s+e)/2+1, e, qs, qe)) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++) cin>> a[i] ;
    cin>> q ;
    vi check(n+1, 1) ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> t ;
        if(t==1)
          {
            cin>> p >> x ;
            a[p]=x ;
            check[p]=i+1 ;
          }
        else
          {
            cin>> x ;
            pay[i]=x ;
          }
      }
    buildTree(1, 1, q) ;
    for(int i=1 ; i<=n ; i++)
      {
        a[i]=max(a[i], query(1, 1, q, check[i], q)) ;
        cout<< a[i] << " " ;
      }
  }
