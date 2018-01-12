#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(cc) (cc).begin(),(cc).end()
using lli = long long int ;
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int n, moves ;
pii home[4], pos[4] ;
bool possible, curr ;

int dist(pii a, pii b)
  {
    return (b.x-a.x)*(b.x-a.x)+(b.y-a.y)*(b.y-a.y) ;
  }

bool check()
  {
    set<int> X ;
    set<pii> Y ;
    for(int i=0 ; i<4 ; i++)
      for(int j=i+1 ; j<4 ; j++)
        X.insert(dist(pos[i], pos[j])) ;
    for(int i=0 ; i<4 ; i++)
      Y.insert(pos[i]) ;
    if(X.size()==2 && Y.size()==4) return true ;
    return false ;
  }

pii rotate(pii pos, pii home)
  {
    pii ans ; int temp ;
    ans=mp(pos.x-home.x, pos.y-home.y) ;
    temp=ans.y ;
    ans.y=ans.x+home.y ;
    ans.x=-temp+home.x ;
    return ans ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n ;
    for(int i=0 ; i<n ; i++)
      {
        for(int j=0 ; j<4 ; j++)
          cin>> pos[j].x >> pos[j].y >> home[j].x >> home[j].y ;
        possible=false ;
        moves=inf ;
        for(int j=0 ; j<4 ; j++)
          {
            for(int k=0 ; k<4 ; k++)
              {
                for(int l=0 ; l<4 ; l++)
                  {
                    for(int m=0 ; m<4 ; m++)
                      {
                        curr=check() ;
                        if(curr)
                          {
                            possible=true ;
                            moves=min(moves, j+k+l+m) ;
                          }
                        pos[3]=rotate(pos[3], home[3]) ;
                      }
                    pos[2]=rotate(pos[2], home[2]) ;
                  }
                pos[1]=rotate(pos[1], home[1]) ;
              }
            pos[0]=rotate(pos[0], home[0]) ;
          }
        if(possible) cout<< moves << endl ;
        else cout<< -1 << endl ;
      }
  }
