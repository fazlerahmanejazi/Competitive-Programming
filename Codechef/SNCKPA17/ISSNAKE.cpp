#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define mod 1000000007
#define endl '\n'
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define all(cc) (cc).begin(),(cc).end()
using pii = pair<int, int> ;
using vi = vector<int> ;
using vb = vector<bool> ;
using vvi = vector<vector<int>> ;
using vlli = vector<long long int> ;
using vpii = vector<pair<int, int>> ;

int T, n, tot, cnt, x, y ;
char plate[2][510] ;
bool visit[2][510] ;

void travel(int i, int j)
  {
    cnt++ ;
    visit[i][j]=true ;
    if(j-1>=0 && !visit[i][j-1]) travel(i, j-1) ;
    else if(i+1<2 && !visit[i+1][j]) travel(i+1, j) ;
    else if(i-1>=0 && !visit[i-1][j]) travel(i-1, j) ;
    else if(j+1<n && !visit[i][j+1]) travel(i, j+1) ;
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> T ;
    while(T--)
      {
        tot=cnt=0 ;
        cin>> n ;
        memset(visit, 1, sizeof visit) ;
        for(int i=0 ; i<2 ; i++)
          for(int j=0 ; j<n ; j++)
            {
              cin>> plate[i][j] ;
              if(plate[i][j]=='#')
                {
                  tot++ ;
                  visit[i][j]=false ;
                }
            }
        for(int j=0 ; j<n ; j++)
          {
            if(!visit[0][j] && !visit[1][j])
              {
                if(j+1<n && visit[0][j+1]) {x=0 ; y=j ; break ;}
                else { x=1 ; y=j ; break ;}
              }
            else if(!visit[0][j]) {x=0 ; y=j ; break ;}
            else if(!visit[1][j]) {x=1 ; y=j ; break ;}
          }
        if(plate[0][0]==plate[1][0])
          for(int j=1 ; j<n ; j++)
            if(plate[0][j]=='.' && plate[0][j-1]=='#') {x=0 ; y=j-1 ; break ;}
            else if(plate[1][j]=='.' && plate[1][j-1]=='#') {x=1 ; y=j-1 ; break ;}
            else if(plate[0][j]!=plate[1][j]) break ;
        travel(x, y) ;
        cout<< ((cnt==tot && tot)? "yes" : "no") << endl;
      }
    }
