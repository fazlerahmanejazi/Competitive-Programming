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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, idx ;
    char c ;
    cin>> n ;
    vb one(10, 1), zero(10, 0) ;
    vector<tuple<char, int, int>> op ;
    for(int i=0 ; i<n ; i++)
      {
        cin>> c >> m ;
        bitset<10> y=m ;
        if(c=='^') for(int j=0 ; j<10 ; j++) one[j]=one[j]^y[j], zero[j]=zero[j]^y[j] ;
        else if(c=='&') for(int j=0 ; j<10 ; j++) one[j]=one[j]&y[j], zero[j]=zero[j]&y[j] ;
        else for(int j=0 ; j<10 ; j++) one[j]=one[j]|y[j], zero[j]=zero[j]|y[j] ;
      }
    for(int i=0 ; i<10 ; i++)
      if(!one[i] && !zero[i]) op.pb(mt('&', 1, i)) ;
      else if(one[i] && zero[i]) op.pb(mt('|', 1, i)) ;
      else if(!one[i] && zero[i]) op.pb(mt('^', 1, i)) ;
    bitset<10> a, o, x ;
    for(int i=0 ; i<10 ; i++) a[i]=1, x[i]=o[i]=0 ;
    for(int i=0 ; i<op.size() ; i++)
      {
        tie(c, ignore, idx)=op[i] ;
        if(c=='^') x[idx]=1 ;
        else if(c=='&') a[idx]=0 ;
        else o[idx]=1 ;
      }
    cout<< 3 << endl ;
    cout<< '&' << " " << a.to_ulong() << endl ;
    cout<< '^' << " " << x.to_ulong() << endl ;
    cout<< '|' << " " << o.to_ulong() << endl ;
  }
