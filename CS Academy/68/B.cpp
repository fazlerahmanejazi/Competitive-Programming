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

#define debug(a) cerr<< #a << ": " << a << endl ;

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, m, K, x1, x2, y1, y2, ans ;
    cin>> n >> m >> K ;
    for(int i=0 ; i<=n ; i++)
      for(int j=0 ; j<=m ; j++)
        for(int k=0 ; k<=n ; k++)
          for(int l=0 ; l<=m ; l++)
            {
              x1=i ; y1=j ;
              x2=k ; y2=l ;
              int temp=0 ;
              if(x1>x2) swap(x1, x2), swap(y1, y2) ;
              else if(x1==x2 && y1>y2) swap(y1, y2) ;
              for(int x3=x1 ; x3<=x2 ; x3++)
                if(x2==x1) temp+=abs(y2-y1)+1 ;
                else if(((x3-x1)*(y2-y1))%(x2-x1)==0 && (((x3-x1)*(y2-y1))/(x2-x1))+y1>=0 && (((x3-x1)*(y2-y1))/(x2-x1))+y1<=m) temp++ ;
               if(temp==K) ans++ ;
            }
    cout<< ans/2 ;
  }
