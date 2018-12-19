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

int n, q, l, r, m, h, t, idx, ans, tree[3][800000], b[200000], a[3][200000], L, R ;

void buildTree(int idx, int s, int e, int t)
  {
    if(s>e) return ;
    if(s==e)
      {
        tree[t][idx]=a[t][s] ;
        return ;
      }
    buildTree(2*idx, s, (s+e)/2, t) ;
    buildTree(2*idx+1, (s+e)/2+1, e, t) ;
    tree[t][idx]=max(tree[t][2*idx], tree[t][2*idx+1]) ;
  }

int query(int idx, int s, int e, int qs, int qe, int t)
  {
    if(qs>e || s>qe) return 0 ;
    if(s>=qs && e<=qe) return tree[t][idx] ;
    return max(query(2*idx, s, (s+e)/2, qs, qe, t), query(2*idx+1, (s+e)/2+1, e, qs, qe, t));
  }

void updateNode(int idx, int s, int e, int pos, int val, int t)
  {
    if(pos<s || pos>e) return ;
    if(s==e)
      {
        tree[t][idx]=val ;
        return ;
      }
    updateNode(2*idx, s, (s+e)/2, pos, val, t) ;
    updateNode(2*idx+1, (s+e)/2+1, e, pos, val, t) ;
    tree[t][idx]=max(tree[t][2*idx],tree[t][2*idx+1]) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> q ;
    for(int i=1 ; i<=n ; i++) cin>> b[i] ;
    a[0][1]=abs(b[2]-b[1]) ;
    a[0][n]=0 ;
    a[1][1]=0 ;
    a[1][n]=abs(b[n]-b[n-1]) ;
    for(int i=2 ; i<n ; i++) a[0][i]=abs(b[i+1]-b[i]), a[1][i]=abs(b[i]-b[i-1]) ;
    buildTree(1, 1, n, 0) ;
    buildTree(1, 1, n, 1) ;
    for(int i=1 ; i<=q ; i++)
      {
        cin>> t >> idx >> h ;
        if(t==1)
          {
            b[idx]=h ;
            if(idx<n) a[0][idx]=abs(b[idx+1]-b[idx]), updateNode(1, 1, n, idx, a[0][idx], 0) ;
            if(idx>1) a[0][idx-1]=abs(b[idx]-b[idx-1]), updateNode(1, 1, n, idx-1, a[0][idx-1], 0) ;
            if(idx>1) a[1][idx]=abs(b[idx]-b[idx-1]), updateNode(1, 1, n, idx, a[1][idx], 1) ;
            if(idx<n) a[1][idx+1]=abs(b[idx+1]-b[idx]), updateNode(1, 1, n, idx+1, a[1][idx+1], 1) ;
          }
        else
          {
            L=R=idx ;
            l=idx+1, r=n ;
            if(idx<n)
              {
                while(l<=r)
                  {
                    m=(l+r)/2 ;
                    if(query(1, 1, n, idx+1, m, 1)<=h) R=m, l=m+1 ;
                    else r=m-1 ;
                  }
              }
            if(idx>1)
              {
                l=1, r=idx-1 ;
                while(l<=r)
                  {
                    m=(l+r)/2 ;
                    if(query(1, 1, n, m, idx-1, 0)<=h) L=m, r=m-1 ;
                    else l=m+1 ;
                  }
              }
            ans=R-L+1 ;
            cout<< ans << endl ;
          }
      }
  }
