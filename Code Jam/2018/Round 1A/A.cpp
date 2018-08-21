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
    int T ;
    cin>> T ;
    for(int tc=1 ; tc<=T ; tc++)
      {
        int r, c, h, v, tot=0, X, Y, curr, p, Z, prev=0 ;
        bool pos=true ;
        vi cntX(110, 0), cntY(110, 0), idxX, idxY ;
        cin>> r >> c >> h >> v ;
        char grid[110][110] ;
        for(int i=1 ; i<=r ; i++)
          for(int j=1 ; j<=c ; j++)
            {
              cin>> grid[i][j] ;
              if(grid[i][j]=='@') tot++, cntX[i]++, cntY[j]++ ;
            }
        if(!(tot%((v+1)*(h+1))) && !(tot%((v+1))) && !(tot%((h+1))))
          {
            X=tot/(h+1) ;
            Z=tot/((v+1)*(h+1)) ;
            curr=p=0 ;
            idxX.pb(0) ;
            for(int i=1 ; i<=r ; i++)
              {
                curr+=cntX[i] ;
                if(curr==X) idxX.pb(i), p++, curr=0 ;
              }
            if(curr==X) idxX.pb(r), p++, curr=0 ;
            if(p!=(h+1)) pos=false ;

            Y=tot/(v+1) ;
            curr=p=0 ;
            idxY.pb(0) ;
            for(int i=1 ; i<=c ; i++)
              {
                curr+=cntY[i] ;
                if(curr==Y) idxY.pb(i), p++, curr=0 ;
              }
            if(curr==Y) idxY.pb(r), p++, curr=0 ;
            if(p!=(v+1)) pos=false ;

            for(int i=0 ; i<idxX.size()-1 ; i++)
              for(int j=0 ; j<idxY.size()-1 ; j++)
                {
                  int a1, a2, b1, b2 ;
                  a1=idxX[i]+1 ; a2=idxX[i+1] ;
                  b1=idxY[j]+1 ; b2=idxY[j+1] ;
                  curr=0 ;
                  for(int k=a1 ; k<=a2 ; k++)
                    for(int l=b1 ; l<=b2 ; l++)
                      if(grid[k][l]=='@') curr++ ;
                  if(curr!=Z) pos=false ;
                }
            if(pos || !tot) cout<< "Case #" << tc << ": POSSIBLE" << endl ;
            else cout<< "Case #" << tc << ": IMPOSSIBLE" << endl ;
          }
        else cout<< "Case #" << tc << ": IMPOSSIBLE" << endl ;
      }
  }
