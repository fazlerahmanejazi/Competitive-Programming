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

#define x(cc) get<0>(cc)
#define y(cc) get<1>(cc)
#define z(cc) get<2>(cc)
#define tt tuple<int, int, int>

tt a, b, c, d ;

tt input()
  {
    int p, q, r ;
    cin>> p >> q >> r ;
    return mt(p, q, r) ;
  }

void output()
  {
    cout<< '(' << x(a) << " " << y(a) << " " << z(a) << ')' ;
    cout<< " (" << x(c) << " " << y(c) << " " << z(c) << ')' <<endl ;
  }

tt move(tt p, int dir)
  {
    if(dir==1) return mt(x(p)+1, y(p), z(p)) ;
    else if(dir==2) return mt(x(p), y(p)+1, z(p)) ;
    else if(dir==3) return mt(x(p), y(p), z(p)+1) ;
    else if(dir==-1) return mt(x(p)-1, y(p), z(p)) ;
    else if(dir==-2) return mt(x(p), y(p)-1, z(p)) ;
    else if(dir==-3) return mt(x(p), y(p), z(p)-1) ;
    else return p ;
  }

int change(tt s, tt e)
  {
    int dir ;
    if(x(s)==x(e))
      {
        if(y(s)==y(e))
          {
            if(z(s)==z(e)) dir=0 ;
            else dir=3*(z(e)-z(s))/abs((z(e)-z(s))) ;
          }
        else dir=2*(y(e)-y(s))/abs((y(e)-y(s))) ;
      }
    else dir=(x(e)-x(s))/abs((x(e)-x(s))) ;
    return dir ;
  }

int get()
  {
    int x=rand()%7-3 ;
    while(!x) x=rand()%7-3 ;
    return x ;
  }

void go(int u, int v)
  {
    if(!u && !v) return ;
    while((move(a, u)==move(c, v) || a==move(c, v) || move(a, u)==c))
      {
        if(u) u=get() ;
        if(v) v=get() ;
      }
    a=move(a, u) ; c=move(c, v) ;
    output() ;
    u=change(a, b) ; v=change(c, d) ;
    go(u, v) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    a=input() ; b=input() ;
    c=input() ; d=input() ;
    int u, v ;
    srand(time(NULL));
    u=change(a, b) ; v=change(c, d) ;
    output() ;
    go(u, v) ;
  }
