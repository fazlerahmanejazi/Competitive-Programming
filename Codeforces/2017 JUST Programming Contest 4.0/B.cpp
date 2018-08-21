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
    int T ;
    cin>> T ;
    while(T--)
      {
        int n, m ;
        cin>> n >> m ;
        vi a(n) ;
        for(int i=0 ; i<n ; i++) cin>> a[i] ;
        for(int i=0 ; i<n ; i++)
          if(a[i]!=-1)
            {
              if(i-1>=0)
                {
                  if(a[i]) a[i-1]=a[i]-1 ;
                  else a[i-1]=m-1 ;
                }
              if(i+1<n) a[i+1]=(a[i]+1)%m ;
            }
        for(int i=n-1 ; i>=0 ; i--)
          if(a[i]!=-1)
            {
              if(i-1>=0)
                {
                  if(a[i]) a[i-1]=a[i]-1 ;
                  else a[i-1]=m-1 ;
                }
              if(i+1<n) a[i+1]=(a[i]+1)%m ;
            }
        for(int i=0 ; i<n ; i++) cout<< a[i] << " " ;
        cout<< endl ;
      }
  }
