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

const int maxn=100010 ;

int n, q, l, r, x, ans, curr, mx ;
vi a(maxn), nge(maxn), dp(maxn, 1) ;
vector<pair<lli, lli>> treeMAX(4*maxn) ;

void buildTreeMax(int idx, int s, int e)
  {
    if(s>e) return ;
    if(s==e) { treeMAX[idx]=mp(a[s], s) ; return ; }
    buildTreeMax(2*idx, s, (s+e)/2) ;
    buildTreeMax(2*idx+1, (s+e)/2+1, e) ;
    if(treeMAX[2*idx].fi>treeMAX[2*idx+1].fi) treeMAX[idx]=treeMAX[2*idx] ;
    else treeMAX[idx]=treeMAX[2*idx+1] ;
  }

pair<lli, lli> queryMax(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return mp(0LL, 0LL) ;
    if(s>=qs && e<=qe) return treeMAX[idx] ;
    pair<lli, lli> x, y ;
    x=queryMax(2*idx, s, (s+e)/2, qs, qe) ;
    y=queryMax(2*idx+1, (s+e)/2+1, e, qs, qe) ;
    if(x.fi>y.fi) return x ;
    else return y ;
  }

void nextGreater()
  {
    stack<lli> S ;
    for (int i=n-1 ; i>=0 ; i--)
      {
        while(!S.empty() && a[S.top()]<=a[i]) S.pop() ;
        if(!S.empty()) nge[i]=S.top() ;
        else nge[i]=i ;
        S.push(i) ;
      }
  }

void fillDP()
  {
    for(int i=n-2 ; i>=0 ; i--) if(nge[i]!=i) dp[i]=dp[nge[i]]+1 ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    for(int i=0 ; i<n ; i++) cin>> a[i] ;
    nextGreater() ;
    fillDP() ;
    buildTreeMax(1, 0, n-1) ;
    for(int i=0 ; i<q ; i++)
      {
        cin>> l >> r ;
        l=(l+ans)%n ;
        r=(r+ans)%n ;
        if(l>r) swap(l, r) ;
        curr=dp[l] ;
        tie(ignore, mx)=queryMax(1, 0, n-1, l, r) ;
        curr-=(dp[mx]-1) ;
        ans=curr ;
        cout<< ans << endl ;
      }
  }
