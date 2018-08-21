#include <bits/stdc++.h>
using namespace std ;

#define inf 0x3f3f3f3f
#define INF 1000111000111000111LL
#define mod 1000000007
#define endl '\n'
#define mp make_pair
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
    lli n ;
    cin>> n ;
    n=n%10 ;
    if(n==0) n=10 ;
    if(n==1) cout<< 1 ;
    else if(n==2) cout<< 2 ;
    else if(n==3) cout<< 3 ;
    else if(n==4) cout<< 1 ;
    else if(n==5) cout<< 2 ;
    else if(n==6) cout<< 3 ;
    else if(n==7) cout<< 1 ;
    else if(n==8) cout<< 2 ;
    else if(n==9) cout<< 3 ;
    else if(n==10) cout<< 4 ;
  }
