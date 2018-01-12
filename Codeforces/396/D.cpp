#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
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

int n, m, q, t, c, x, y, S, R ;
string s, r ;
vi p, opp ;
map<string, int> cnv ;

int find(int i)
  {
    if(i!=p[i]) p[i]=find(p[i]) ;
    return p[i] ;
  }
bool same(int i, int j)
  {
    return find(i)==find(j) ;
  }
void unionset(int i, int j)
  {
    if(i==-1 || j==-1) return ;
    int x=find(i) ; int y=find(j) ;
    if(x!=y) p[x]=y ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ;
    cin>> n >> m >> q ;
    c=1 ;
    p.resize(n+1) ;
    opp.assign(n+1, -1) ;
    for(int i=1 ; i<=n ; i++)
      {
        cin>> s ;
        cnv[s]=c++ ;
        p[i]=i ;
      }
    for(int i=0 ; i<m ; i++)
      {
        cin>> t >> s >> r ;
        S=cnv[s] ; R=cnv[r] ;
        x=opp[find(S)] ; y=opp[find(R)] ;
        if(t==1)
          {
            if(x==find(R) && y==find(S)) cout<< "NO" << endl ;
            else if(x!=-1 && y!=-1 && y==opp[find(x)] && x==opp[find(y)]) cout<< "NO" << endl ;
            else
              {
                cout<< "YES" << endl ;
                unionset(x, y) ;
                unionset(S, R) ;
                x=max(x, y) ;
                if(x!=-1)
                  {
                    opp[find(x)]=find(S) ;
                    opp[find(S)]=find(x) ;
                  }
              }
          }
        else
          {
            if(find(S)==find(R)) cout<< "NO" << endl ;
            else if(x==y && x!=-1) cout<< "NO" << endl ;
            else
              {
                cout<< "YES" << endl ;
                unionset(x, R) ;
                unionset(y, S) ;
                opp[find(S)]=find(R) ;
                opp[find(R)]=find(S) ;
              }
          }
      }
    for(int i=0 ; i<q ; i++)
      {
        cin>> s >> r ;
        S=cnv[s] ; R=cnv[r] ;
        x=opp[find(S)] ; y=opp[find(R)] ;
        if(same(S, R)) cout << 1 << endl ;
        else if(x==find(R) && y==find(S)) cout<< 2 << endl ;
        else cout<< 3 << endl ;
      }
  }
