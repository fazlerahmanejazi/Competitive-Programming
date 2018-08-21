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
    vi a(3) ;
    cin>> a[0] >> a[1] >> a[2] ;
    sort(all(a)) ;
    int N=2*a[2]+1 ;
    do
      {
        for(int i=1 ; i<a[0] ; i++)
          {
            int s=1 ;
            bool lit[N], check=true ;
            memset(lit, false, sizeof lit) ;
            lit[a[0]]=lit[2*a[0]]=true ;
            for(int j=i ; j<N ; j+=a[1]) lit[j]=true ;
            for(int j=1 ; j<N ; j++)
              if(!lit[j])
                {
                  s=j ;
                  break ;
                }
            for(int j=s ; j<N ; j+=a[2]) lit[j]=true ;
            for(int j=1 ; j<N ; j++) if(!lit[j]) check=false ;
            if(check)
              {
                cout<< "YES" ;
                return 0 ;
              }
          }
      } while(next_permutation(all(a))) ;
    cout<< "NO" ;
  }
