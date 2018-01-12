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

int T, n, x ;
vvi adj ;
vi a, b, two, one ;

void init()
  {
    adj.clear() ; adj.resize(100005) ;
    a.clear() ; a.resize(n+1) ;
    b.clear() ; b.resize(n+1) ;
    one.clear() ; two.clear() ;
  }

void solvePair()
  {
    int p, q ;
    if(two.empty()) return ;
    two.pb(two[0]) ;
    for(int i=0 ; i<two.size()-1 ; i++)
      {
        p=two[i] ; q=two[i+1] ;
        b[adj[q][0]]=b[adj[q][1]]=p ;
      }
  }

void solveSingle()
  {
    int p, q ;
    if(one.empty()) return ;
    one.pb(one[0]) ;
    for(int i=0 ; i<one.size()-1 ; i++)
      {
        p=one[i] ; q=one[i+1] ;
        b[adj[q][0]]=p ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        cin>> n ;
        init() ;
        for(int i=1 ; i<=n ; i++)
          {
            cin>> a[i] ;
            adj[a[i]].pb(i) ;
          }
        for(int i=1 ; i<=100000 ; i++)
          if(adj[i].size()==2) two.pb(i) ;
          else if(adj[i].size()==1) one.pb(i) ;
        solvePair() ; solveSingle() ;
        if(one.size()==2 && two.size()==2)
          {
            cout<< n-1 << endl << a[n] << " " ;
            for(int i=1 ; i<n ; i++) cout<< a[i] << " " ;
          }
        else if(one.size()==2)
          {
            if(!two.size()) cout<< 0 << endl << a[1] ;
            else
              {
                int pos=adj[one[0]][0] ;
                for(int i=1 ; i<=n ; i++)
                  if(b[i]!=one[0])
                    {
                      b[pos]=b[i] ;
                      b[i]=one[0] ;
                      break ;
                    }
                cout<< n << endl ;
                for(int i=1 ; i<=n ; i++) cout<< b[i] << " " ;
              }
          }
        else if(two.size()==2)
          {
            if(!one.size()) cout<< 0 << endl << a[2] << " " << a[1] ;
            else
              {
                int pos=adj[two[0]][0], c=0 ;
                for(int i=1 ; i<=n ; i++)
                  if(b[i]!=two[0])
                    {
                      b[pos]=b[i] ;
                      b[i]=two[0] ;
                      pos=adj[two[0]][1] ;
                      if(c==1) break ;
                      c++ ;
                    }
                cout<< n << endl ;
                for(int i=1 ; i<=n ; i++) cout<< b[i] << " " ;
              }
          }
        else
          {
            cout<< n << endl ;
            for(int i=1 ; i<=n ; i++) cout<< b[i] << " " ;
          }
        cout<< endl ;
      }
  }
