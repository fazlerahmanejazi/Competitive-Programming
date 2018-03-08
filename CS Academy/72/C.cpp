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

int n, m, x ;
lli ans ;
vvi mat, a, b, mx(3), my(3) ;

void pre()
  {
    for(int i=1 ; i<n ; i++)
      for(int j=1 ; j<m ; j++)
        {
          mat[i][j]++ ;
          mat[i+1][j]++ ;
          mat[i][j+1]++ ;
          mat[i+1][j+1]++ ;
        }
    for(int i=1 ; i<=m ; i++)
      {
        mx[1].pb(mat[1][i]) ;
        mx[2].pb(mat[2][i]) ;
      }
    for(int i=1 ; i<=n ; i++)
      {
        my[1].pb(mat[i][1]) ;
        my[2].pb(mat[i][2]) ;
      }
  }

lli calc(vvi &c, vvi &M)
  {
    lli res=0, curr, base ;
    vlli val1(n+1, 0), val2(n+1, 0) ;
    for(int i=1 ; i<=n ; i++)
      {
        for(int j=1 ; j<=m ; j++)
          {
            val1[i]+=M[1][j-1]*c[i][j] ;
            val2[i]+=M[2][j-1]*c[i][j] ;
          }
        if(i==1 || i==n) res+=val1[i] ;
        else res+=val2[i] ;
      }
    base=res ;
    for(int i=2 ; i<n ; i++)
      {
        curr=base-val2[i]-val1[1]+val1[i]+val2[1] ;
        res=max(curr, res) ;
        curr=base-val2[i]-val1[n]+val1[i]+val2[n] ;
        res=max(curr, res) ;
      }
    return res ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> m ;
    mat.assign(n+1, vi(m+1, 0)) ;
    pre() ;
    a.assign(n+1, vi(m+1, 0)) ;
    b.assign(m+1, vi(n+1, 0)) ;
    for(int i=1 ; i<=n ; i++)
      for(int j=1 ; j<=m ; j++)
        {
          cin>> x ;
          a[i][j]=b[j][i]=x ;
        }
    ans=calc(a, mx) ;
    swap(n, m) ;
    ans=max(ans, calc(b, my)) ;
    cout<< ans ;
  }
