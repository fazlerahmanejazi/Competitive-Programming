#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000009
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

int n, k ;
vector<long long int> sz(37) ;

string f(int n)
  {
    if(n==0) return "a" ;
    if(n==1) return "b" ;
    if(n==2) return "c" ;
    if(k<=sz[n-1]) return f(n-1) ;
    else if(k<=sz[n-1]+sz[n-2])
      {
        k=k-sz[n-1] ;
        return f(n-2) ;
      }
    else if(k<=sz[n-1]+sz[n-2]+sz[n-3])
      {
        k=k-sz[n-2]-sz[n-1] ;
        return f(n-3) ;
      }
  }

int main()
  {
    ios_base::sync_with_stdio (false) ; cin.tie(0) ; cout.tie(0) ;
    cin>> n >> k ;
    sz[0]=1 ; sz[1]=1 ; sz[2]=1 ;
    for(int i=3 ; i<=n ; i++)
      sz[i]=sz[i-1]+sz[i-2]+sz[i-3] ;
    if(sz[n]<k) cout<< -1 ;
    else cout<< f(n) ;
  }
