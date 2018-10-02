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

#define ld long double

int n, q, idx, t, l, r ;
ld a[100005], x, ans, tree[400005] ;

bool isFinite(ld x)
  {
    return x<69.314718055994530941723212145818 ;
  }

void buildTree(int idx, int s, int e)
  {
    if(s>e) return ;
    if(s==e)
      {
        tree[idx]=a[s] ;
        return ;
      }
    buildTree(2*idx, s, (s+e)/2) ;
    buildTree(2*idx+1, (s+e)/2+1, e) ;
    tree[idx]=tree[2*idx]+tree[2*idx+1] ;
  }

ld query(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return 0 ;
    if(s>=qs && e<=qe) return tree[idx] ;
    return query(2*idx, s, (s+e)/2, qs, qe)+query(2*idx+1, (s+e)/2+1, e, qs, qe) ;
  }

void updateNode(int idx, int s, int e, int pos, ld val)
  {
    if(pos<s || pos>e) return ;
    if(s==e)
      {
        tree[idx]=val ;
        return ;
      }
    updateNode(2*idx, s, (s+e)/2, pos, val) ;
    updateNode(2*idx+1, (s+e)/2+1, e, pos, val) ;
    tree[idx]=tree[2*idx]+tree[2*idx+1] ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++) cin>> a[i], a[i]=log(a[i]) ;
    buildTree(1, 0, n-1) ;
    cin>> q ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> t ;
        if(t==1) cin>> idx >> x, updateNode(1, 0, n-1, idx-1, log(x)) ;
        else
          {
            cin>> l >> r ;
            ans=query(1, 0, n-1, l-1, r-1) ;
            if(isFinite(ans)) cout<< fixed << setprecision(9) << exp(ans) << endl ;
            else cout<< "INFINITE!" << endl ;
          }
      }
  }
