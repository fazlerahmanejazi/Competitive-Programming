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

int n, x, curr, l, r, m, idx ;
int a[300000], tree[900000], nge[300000], far[300000], ans[300000] ;

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
    tree[idx]=min(tree[2*idx], tree[2*idx+1]) ;
  }

int query(int idx, int s, int e, int qs, int qe)
  {
    if(qs>e || s>qe) return inf ;
    if(s>=qs && e<=qe) return tree[idx] ;
    return min(query(2*idx, s, (s+e)/2, qs, qe), query(2*idx+1, (s+e)/2+1, e, qs, qe));
  }

void nextGreater()
  {
    stack<lli> S ;
    for (int i=2*n ; i>=0 ; i--)
      {
        while(!S.empty() && a[S.top()]<=a[i]) S.pop() ;
        if(!S.empty()) nge[i]=S.top() ;
        else nge[i]=2*n ;
        S.push(i) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x ;
        a[i]=a[i+n]=x ;
      }
    nextGreater() ;
    buildTree(0, 1, 2*n) ;
    for(int i=1 ; i<=2*n ; i++)
      {
        l=idx=i ; r=nge[i]-1 ;
        while(l<=r)
          {
            m=(l+r)/2 ;
            curr=2*query(0, 1, 2*n, l, m) ;
            if(curr>=a[i]) l=m+1, idx=m ;
            else r=m-1 ;
          }
        far[i]=idx ;
      }
    for(int i=2*n ; i>=1 ; i--)
      {
        if(far[i]+1==nge[i]) ans[i]=ans[nge[i]]+(far[i]-i+1) ;
        else ans[i]=far[i]-i+1 ;
      }
    for(int i=1 ; i<=n ; i++) cout<< ans[i] << " " ;
  }
