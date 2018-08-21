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

const int MX=200005 ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    lli n, q, mx=0, cnt=0, pos=0 ;
    cin>> n >> q ;
    vlli a(MX, 0), b(MX, 0), c(MX, 0), taken(MX, 0) ;
    set<lli>temp ;
    set<lli>::iterator it ;
    temp.insert(0) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>>a[i] ;
        mx=max(a[i], mx) ;
        if(!a[i])
          {
            cnt++ ;
            pos=i ;
            if(i==1) a[i]=1 ;
            else a[i]=a[i-1] ;
          }
      }
    if(mx<q)
      {
        if(!cnt) return cout<< "NO" << endl, 0 ;
        else a[pos]=q ;
      }
    for(int i=1 ; i<=n ; i++) if(!taken[a[i]]) taken[a[i]]=1, b[i]=a[i] ;
    for(int i=n ; i>=1 ; i--) if(taken[a[i]]==1) taken[a[i]]=2, c[i]=a[i] ;
    for(int i=1 ; i<=n ; i++)
      {
        it=temp.end() ; it-- ;
        if((*it)>a[i]) return cout<< "NO" << endl, 0 ;
        if(b[i]>0) temp.insert(b[i]) ;
        if(c[i]>0) temp.erase(c[i]) ;
      }
    cout<< "YES" << endl ;
    for(int i=1 ; i<=n ; i++) cout<< a[i] << " " ;
  }
