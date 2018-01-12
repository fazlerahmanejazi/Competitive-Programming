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

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    int n, k, c=1, m ;
    cin>> n >> k ;
      {
        if(n==2)
          {
            if(!k) cout<< -1 ;
            else cout<< 1 << " " << 2 << " " << 1 ;
           }
        else if(n==3 && !k) cout<< -1 ;
        else
          {
            m=2*(n-1)-k ;
            cout<< m << endl ;
            int u, v ;
            for(int i=n ; i>1 ; i--, m--) cout<< i << " " << i-1 << " " << c++ << endl ;
            u=max(k, 1), v=u+2 ;
            while(m--)
              {
                cout<< u << " " << v << " " << c++ << endl ;
                v++ ;
                if(v>n) u+=1, v=u+2 ;
              }
          }
      }
  }
