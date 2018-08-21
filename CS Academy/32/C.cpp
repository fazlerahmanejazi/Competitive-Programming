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
    int n, ans=0 ;
    cin>> n ;
    vi a(n) ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    map<int, bool> taken, used ;
    taken[a[0]]=true ;
    ans=1 ;
    for(int i=1 ; i<n ; i++)
      {
        if(taken[a[i]] && a[i-1]!=a[i] && !used[a[i]])
          {
            ans-- ;
            used[a[i]]=true ;
          }
        else if(!taken[a[i]])
          {
            ans++ ;
            taken[a[i]]=true ;
          }
      }
    cout<< max(ans, 0) ;
  }
