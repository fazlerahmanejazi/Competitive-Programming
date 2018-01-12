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

vi p ;

int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }

void unionset(int i, int j)
  {
    int x=find(i) ; int y=find(j) ;
    if(x!=y) p[x]=y ;
  }

bool check(string a, string b)
  {
    for(int i=0 ; i<4 ; i++)
      {
        bool pos=true ;
        for(int j=0 ; j<4 ; j++)
          if(a[i+j]!=b[j])
            pos=false ;
        if(pos) return true ;
      }
    return false ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, ans=0 ;
    vector<string> a ;
    a.pb("") ;
    string x, y, z ;
    cin>> n ;
    p.resize(n+1) ;
    vb taken(n+1, false) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> x >> y ;
        z="" ;
        z+=x[0] ; z+=x[1] ; z+=y[1] ; z+=y[0] ;
        z+=z ;
        a.pb(z) ;
        p[i]=i ;
        if(i<n) cin>> z ;
      }
    for(int i=1 ; i<=n ; i++)
      for(int j=i+1 ; j<=n ; j++)
        if(check(a[i], a[j]))
          unionset(i, j) ;
    for(int i=1 ; i<=n ; i++) if(!taken[find(i)]) ans++, taken[find(i)]=true ;
    cout<< ans ;
  }
