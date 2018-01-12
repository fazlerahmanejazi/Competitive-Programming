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
    int n, k, pos, idx ;
    bool possible ;
    cin>> n >> k ;
    vi a(n) ;
    set<int> check ;
    for(int i=0 ; i<n ; i++)
      cin>> a[i] ;
    if(n==2 && abs(a[1]-a[0])>k)
      {
        cout<< -1 ;
        return 0 ;
      }
    for(int i=1 ; i<n ; i++)
      if(abs(a[i]-a[i-1])>k)
        {
          check.insert(i) ;
          check.insert(i-1) ;
          i++ ;
        }
    auto it=check.begin() ;
    if(check.size()>10)
      {
        cout<< -1 ;
        return 0 ;
      }
    while(it!=check.end())
      {
        pos=*it ;
        for(int i=0 ; i<n ; i++)
          if(pos!=i)
            {
              possible=true ;
              swap(a[pos], a[i]) ;
              auto x=check.begin() ;
              while(x!=check.end())
                {
                  idx=*x ;
                  if(idx+1<n && abs(a[idx]-a[idx+1])>k) possible=false ;
                  if(idx-1>=0 && abs(a[idx]-a[idx-1])>k) possible=false ;
                  x++ ;
                }
              if(i+1<n && abs(a[i]-a[i+1])>k) possible=false ;
              if(i-1>=0 && abs(a[i]-a[i-1])>k) possible=false ;
              if(possible)
                {
                  cout<< min(pos+1, i+1) << " " << max(pos+1, i+1) ;
                  return 0 ;
                }
              swap(a[pos], a[i]) ;
            }
        it++ ;
      }
    if(check.empty()) cout<< 0 ;
    else cout<< -1 ;
  }
